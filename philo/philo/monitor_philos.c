/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_philos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 18:15:42 by marnaudy          #+#    #+#             */
/*   Updated: 2022/04/14 12:21:54 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	end_simulation(t_global *data)
{
	if (pthread_mutex_lock(&data->end_mutex))
		return ;
	data->end_simulation = 1;
	pthread_mutex_unlock(&data->end_mutex);
}

int	join_threads(t_global *data, t_philo_arg *arg_array, int n, int dead_philo)
{
	int	i;

	end_simulation(data);
	if (dead_philo >= 0)
		display_state(data, dead_philo, dead);
	if (n < 0)
		n = data->nb_philo;
	i = 0;
	while (i < n)
	{
		if (pthread_join(data->philo[i].thread, NULL))
			return (-1);
		i++;
	}
	free(arg_array);
	return (0);
}

static int	philo_is_done(t_global *data, unsigned int philo_nb)
{
	int	philo_status;

	if (pthread_mutex_lock(&data->philo[philo_nb].happiness_mutex))
		return (-1);
	philo_status = data->philo[philo_nb].is_happy;
	pthread_mutex_unlock(&data->philo[philo_nb].happiness_mutex);
	return (philo_status);
}

int	monitor_threads(t_global *data, t_philo_arg *arg_array)
{
	int				philos_are_happy;
	unsigned int	i;

	while (1)
	{
		philos_are_happy = 1;
		i = 0;
		while (i < data->nb_philo)
		{
			if (time_until_death(data, i) < 0)
				return (join_threads(data, arg_array, -1, i));
			if (!philo_is_done(data, i))
				philos_are_happy = 0;
			i++;
		}
		if (philos_are_happy)
			return (join_threads(data, arg_array, -1, -1));
		usleep(1000);
	}
	return (0);
}

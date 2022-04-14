/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 16:07:06 by marnaudy          #+#    #+#             */
/*   Updated: 2022/04/14 14:44:29 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	philo_sleep(t_global *data, unsigned int philo_nb)
{
	if (display_state(data, philo_nb, sleeping))
		return (-1);
	usleep(data->time_sleep * 1000);
	return (0);
}

static int	think(t_global *data, unsigned int philo_nb)
{
	int	life_expectancy;

	life_expectancy = time_until_death(data, philo_nb);
	if (life_expectancy < 0)
		return (-1);
	if (display_state(data, philo_nb, thinking))
		return (-1);
	while (1)
	{
		if (life_expectancy < 20)
			return (0);
		usleep(10000);
		life_expectancy = time_until_death(data, philo_nb);
	}
}

static int	eat(t_global *data, unsigned int philo_nb, int day_nb)
{
	if (update_last_meal(data, philo_nb)
		|| display_state(data, philo_nb, eating))
	{
		pthread_mutex_unlock(data->philo[philo_nb].left);
		pthread_mutex_unlock(data->philo[philo_nb].right);
		return (-1);
	}
	if (day_nb + 1 == data->nb_days)
		philo_is_happy(data, philo_nb);
	usleep(data->time_eat * 1000);
	if (pthread_mutex_unlock(data->philo[philo_nb].left))
		return (-1);
	if (pthread_mutex_unlock(data->philo[philo_nb].right))
		return (-1);
	return (0);
}

static int	try_to_eat(t_global *data, unsigned int philo_nb, int day_nb)
{
	if (is_the_end(data))
		return (-1);
	if (pthread_mutex_lock(data->philo[philo_nb].left))
		return (-1);
	if (display_state(data, philo_nb, fork_pickup))
	{
		pthread_mutex_unlock(data->philo[philo_nb].left);
		return (-1);
	}
	if (data->philo[philo_nb].right == data->philo[philo_nb].left
		|| pthread_mutex_lock(data->philo[philo_nb].right))
	{
		pthread_mutex_unlock(data->philo[philo_nb].left);
		return (-1);
	}
	if (display_state(data, philo_nb, fork_pickup))
	{
		pthread_mutex_unlock(data->philo[philo_nb].left);
		pthread_mutex_unlock(data->philo[philo_nb].right);
		return (-1);
	}
	eat(data, philo_nb, day_nb);
	return (0);
}

void	*simulate(void *arg_void)
{
	t_philo_arg	*arg;
	int			days;

	arg = (t_philo_arg *) arg_void;
	days = 0;
	if (arg->data->nb_days == 0)
		philo_is_happy(arg->data, arg->philo_nb);
	if(arg->philo_nb % 2)
		usleep(3000);
	while (1)
	{
		if (try_to_eat(arg->data, arg->philo_nb, days))
			return (NULL);
		days++;
		if (philo_sleep(arg->data, arg->philo_nb)
			|| think(arg->data, arg->philo_nb))
			return (NULL);
	}
}

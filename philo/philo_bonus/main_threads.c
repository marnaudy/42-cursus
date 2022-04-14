/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 12:43:04 by marnaudy          #+#    #+#             */
/*   Updated: 2022/04/12 16:49:44 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	*monitor_philo_happiness(void *void_data)
{
	t_global		*data;
	unsigned int	nb_happy_philos;

	data = (t_global *)void_data;
	nb_happy_philos = 0;
	while (1)
	{
		if (sem_wait(data->philo_is_happy))
			return (NULL);
		nb_happy_philos++;
		if (nb_happy_philos == data->nb_philo)
		{
			sem_post(data->philo_is_dead);
			return (NULL);
		}
		usleep(10000);
	}
}

static void	*monitor_philo_death(void *void_data)
{
	t_global		*data;
	unsigned int	i;

	data = (t_global *)void_data;
	if (sem_wait(data->philo_is_dead))
		return (NULL);
	sem_post(data->end_simulation);
	i = 0;
	while (i < data->nb_philo)
	{
		sem_post(data->philo_is_happy);
		sem_post(data->forks);
		i++;
	}
	return (NULL);
}

void	launch_main_threads(t_global *data)
{
	if (pthread_create(&data->monitor_1, NULL,
			&monitor_philo_death, (void *)data))
	{
		sem_post(data->end_simulation);
		return ;
	}
	if (pthread_create(&data->monitor_2, NULL,
			&monitor_philo_happiness, (void *)data))
	{
		sem_post(data->philo_is_dead);
		pthread_join(data->monitor_1, NULL);
		return ;
	}
	pthread_join(data->monitor_1, NULL);
	pthread_join(data->monitor_2, NULL);
}

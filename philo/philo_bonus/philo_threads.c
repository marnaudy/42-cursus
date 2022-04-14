/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 11:45:05 by marnaudy          #+#    #+#             */
/*   Updated: 2022/04/14 09:12:37 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	*philo_life_monitoring(void	*data_and_nb)
{
	t_global		*data;
	unsigned int	philo_nb;
	int				life_expectancy;

	data = ((t_global_and_nb *)data_and_nb)->data;
	philo_nb = ((t_global_and_nb *)data_and_nb)->philo_nb;
	while (1)
	{
		life_expectancy = time_until_death(data);
		if (!want_to_live(data))
			return (NULL);
		if (life_expectancy < 0)
		{
			display_state(data, philo_nb, dead);
			sem_post(data->philo_is_dead);
			if (sem_wait(data->will_to_live_access))
				return (NULL);
			data->will_to_live = 0;
			sem_post(data->will_to_live_access);
			return (NULL);
		}
		usleep(100);
	}
}

static void	*philo_end_simulation_monitoring(void *void_data)
{
	t_global	*data;

	data = (t_global *)void_data;
	sem_wait(data->end_simulation);
	sem_post(data->end_simulation);
	sem_wait(data->will_to_live_access);
	data->will_to_live = 0;
	sem_post(data->will_to_live_access);
	return (NULL);
}

static void	exit_threads(t_global *data, unsigned int philo_nb, int free_sem)
{
	close_global_sem(data);
	if (free_sem)
		unlink_philo_sem(data, philo_nb);
	free(data->pid);
	free(data);
	exit(0);
}

static void	join_philo_threads_and_exit(t_global *data, unsigned int philo_nb)
{
	pthread_join(data->monitor_1, NULL);
	pthread_join(data->monitor_2, NULL);
	exit_threads(data, philo_nb, 1);
}

void	launch_philo_threads(t_global *data, unsigned int philo_nb)
{
	t_global_and_nb	data_and_nb;

	data_and_nb.data = data;
	data_and_nb.philo_nb = philo_nb;
	if (init_philo_sem(data, philo_nb))
		exit_threads(data, philo_nb, 0);
	if (pthread_create(&data->monitor_1, NULL,
			&philo_end_simulation_monitoring, (void *)data))
	{
		sem_post(data->philo_is_dead);
		exit_threads(data, philo_nb, 1);
	}
	if (pthread_create(&data->monitor_2, NULL,
			&philo_life_monitoring, (void *)&data_and_nb))
	{
		sem_post(data->philo_is_dead);
		pthread_join(data->monitor_1, NULL);
		exit_threads(data, philo_nb, 1);
	}
	simulate(data, philo_nb);
	join_philo_threads_and_exit(data, philo_nb);
}

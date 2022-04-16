/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_monitoring.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 19:01:05 by marnaudy          #+#    #+#             */
/*   Updated: 2022/04/16 19:24:24 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	*kill_philo(t_global *data, unsigned int philo_nb)
{
	if (sem_wait(data->philo_is_dying))
		return (NULL);
	if (!want_to_live(data))
	{
		sem_post(data->philo_is_dying);
		return (NULL);
	}
	sem_post(data->philo_is_dead);
	sem_wait(data->will_to_live_access);
	data->will_to_live = 0;
	sem_post(data->will_to_live_access);
	usleep(2000);
	display_state(data, philo_nb, dead);
	sem_post(data->philo_is_dying);
	return (NULL);
}

void	*philo_life_monitoring(void	*data_and_nb)
{
	t_global		*data;
	unsigned int	philo_nb;
	int				life_expectancy;

	data = ((t_global_and_nb *)data_and_nb)->data;
	philo_nb = ((t_global_and_nb *)data_and_nb)->philo_nb;
	while (1)
	{
		if (!want_to_live(data))
			return (NULL);
		life_expectancy = time_until_death(data);
		if (life_expectancy < 0)
			return (kill_philo(data, philo_nb));
		usleep(100);
	}
}

void	*philo_end_simulation_monitoring(void *void_data)
{
	t_global	*data;

	data = (t_global *)void_data;
	sem_wait(data->end_simulation);
	sem_wait(data->will_to_live_access);
	data->will_to_live = 0;
	sem_post(data->will_to_live_access);
	return (NULL);
}

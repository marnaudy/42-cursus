/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 17:33:31 by marnaudy          #+#    #+#             */
/*   Updated: 2022/04/06 12:15:24 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_the_end(t_global *data)
{
	int	the_end;

	if (pthread_mutex_lock(&data->end_mutex))
		return (-1);
	the_end = data->end_simulation;
	if (pthread_mutex_unlock(&data->end_mutex))
		return (-1);
	return (the_end);
}

void	*philo_is_happy(t_global *data, unsigned int philo_nb)
{
	if (pthread_mutex_lock(&data->philo[philo_nb].happiness_mutex))
		return (NULL);
	data->philo[philo_nb].is_happy = 1;
	pthread_mutex_unlock(&data->philo[philo_nb].happiness_mutex);
	return (NULL);
}

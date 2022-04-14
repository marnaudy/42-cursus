/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 12:23:23 by marnaudy          #+#    #+#             */
/*   Updated: 2022/04/06 12:18:48 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_time(t_global *data)
{
	unsigned int	i;

	if (gettimeofday(&data->start, NULL))
		return (1);
	i = 0;
	while (i < data->nb_philo)
	{
		data->philo[i].last_meal.tv_sec = data->start.tv_sec;
		data->philo[i].last_meal.tv_usec = data->start.tv_usec;
		i++;
	}
	return (0);
}

int	timestamp(t_global *data)
{
	struct timeval	now;
	int				difference;

	if (gettimeofday(&now, NULL))
		return (-1);
	difference = (now.tv_usec - data->start.tv_usec) / 1000;
	difference += (now.tv_sec - data->start.tv_sec) * 1000;
	return (difference);
}

int	time_since_last_meal(t_global *data, unsigned int philo_nb)
{
	struct timeval	now;
	int				difference;

	if (pthread_mutex_lock(&data->philo[philo_nb].meal_mutex))
		return (-1);
	if (gettimeofday(&now, NULL))
		return (-1);
	difference = (now.tv_usec - data->philo[philo_nb].last_meal.tv_usec)
		/ 1000;
	difference += (now.tv_sec - data->philo[philo_nb].last_meal.tv_sec)
		* 1000;
	if (pthread_mutex_unlock(&data->philo[philo_nb].meal_mutex))
		return (-1);
	return (difference);
}

int	time_until_death(t_global *data, unsigned int philo_nb)
{
	int	last_meal;

	last_meal = time_since_last_meal(data, philo_nb);
	if (last_meal < 0)
		return (-1);
	return (data->time_die - last_meal);
}

int	update_last_meal(t_global *data, unsigned int philo_nb)
{
	if (pthread_mutex_lock(&data->philo[philo_nb].meal_mutex))
		return (-1);
	if (gettimeofday(&data->philo[philo_nb].last_meal, NULL))
		return (-1);
	if (pthread_mutex_unlock(&data->philo[philo_nb].meal_mutex))
		return (-1);
	return (0);
}

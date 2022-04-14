/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 12:23:23 by marnaudy          #+#    #+#             */
/*   Updated: 2022/04/12 11:01:19 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	init_time(t_global *data)
{
	if (gettimeofday(&data->start, NULL))
		return (1);
	data->last_meal.tv_sec = data->start.tv_sec;
	data->last_meal.tv_usec = data->start.tv_usec;
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

int	time_since_last_meal(t_global *data)
{
	struct timeval	now;
	int				difference;

	if (sem_wait(data->last_meal_access))
		return (-1);
	if (gettimeofday(&now, NULL))
		return (-1);
	difference = (now.tv_usec - data->last_meal.tv_usec)
		/ 1000;
	difference += (now.tv_sec - data->last_meal.tv_sec)
		* 1000;
	if (sem_post(data->last_meal_access))
		return (-1);
	return (difference);
}

int	time_until_death(t_global *data)
{
	int	last_meal;

	last_meal = time_since_last_meal(data);
	if (last_meal < 0)
		return (-1);
	return (data->time_die - last_meal);
}

int	update_last_meal(t_global *data)
{
	if (sem_wait(data->last_meal_access))
		return (-1);
	if (gettimeofday(&data->last_meal, NULL))
		return (-1);
	if (sem_post(data->last_meal_access))
		return (-1);
	return (0);
}

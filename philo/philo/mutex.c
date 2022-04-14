/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 09:30:18 by marnaudy          #+#    #+#             */
/*   Updated: 2022/04/07 17:06:28 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	destroy_n_forks(t_global *data, int n)
{
	int	i;

	i = 0;
	if (n < 0)
		n = data->nb_philo;
	while (i < n)
	{
		pthread_mutex_destroy(data->forks + i);
		i++;
	}
	pthread_mutex_destroy(&data->end_mutex);
	pthread_mutex_destroy(&data->print_mutex);
}

static void	assign_forks(t_global *data)
{
	unsigned int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		data->philo[i].left = data->forks + i + (i % 2 == 0);
		data->philo[i].right = data->forks + i + i % 2;
		i++;
	}
	if (data->nb_philo % 2)
		data->philo[data->nb_philo - 1].left = data->forks;
	else
		data->philo[data->nb_philo - 1].right = data->forks;
}

void	destroy_n_philo_mutex(t_global *data, int n1, int n2)
{
	int	i;

	i = 0;
	if (n1 < 0)
		n1 = data->nb_philo;
	while (i < n1)
	{
		pthread_mutex_destroy(&data->philo[i].happiness_mutex);
		i++;
	}
	i = 0;
	if (n2 < 0)
		n2 = data->nb_philo;
	while (i < n2)
	{
		pthread_mutex_destroy(&data->philo[i].meal_mutex);
		i++;
	}
	destroy_n_forks(data, -1);
}

int	init_philo_mutex(t_global *data)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (i < data->nb_philo)
	{
		if (pthread_mutex_init(&data->philo[i].happiness_mutex, NULL))
		{
			destroy_n_philo_mutex(data, i, j);
			return (-1);
		}
		i++;
		if (pthread_mutex_init(&data->philo[j].meal_mutex, NULL))
		{
			destroy_n_philo_mutex(data, i, j);
			return (-1);
		}
		j++;
	}
	return (0);
}

int	init_mutex(t_global *data)
{
	unsigned int	i;

	if (pthread_mutex_init(&data->print_mutex, NULL))
		return (-1);
	if (pthread_mutex_init(&data->end_mutex, NULL))
	{
		pthread_mutex_destroy(&data->print_mutex);
		return (-1);
	}
	i = 0;
	while (i < data->nb_philo)
	{
		if (pthread_mutex_init(data->forks + i, NULL))
		{
			destroy_n_forks(data, i);
			return (1);
		}
		i++;
	}
	assign_forks(data);
	if (init_philo_mutex(data))
		return (-1);
	return (0);
}

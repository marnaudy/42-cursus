/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 12:22:29 by marnaudy          #+#    #+#             */
/*   Updated: 2022/04/06 16:34:11 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_philo_arg	*init_args(t_global *data)
{
	unsigned int	i;
	t_philo_arg		*arg_array;

	arg_array = malloc(data->nb_philo * sizeof(t_philo_arg));
	if (!arg_array)
		return (NULL);
	i = 0;
	while (i < data->nb_philo)
	{
		arg_array[i].data = data;
		arg_array[i].philo_nb = i;
		i++;
	}
	return (arg_array);
}

int	launch_threads(t_global *data)
{
	unsigned int	i;
	t_philo_arg		*arg_array;

	i = 0;
	arg_array = init_args(data);
	if (!arg_array)
		return (-1);
	if (init_time(data))
	{
		free(arg_array);
		return (-1);
	}
	while (i < data->nb_philo)
	{
		if (pthread_create(&data->philo[i].thread, NULL,
				&simulate, (void *)(arg_array + i)))
		{
			join_threads(data, arg_array, i);
			return (-1);
		}
		usleep(10);
		i++;
	}
	return (monitor_threads(data, arg_array));
}

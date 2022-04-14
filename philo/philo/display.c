/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 12:20:59 by marnaudy          #+#    #+#             */
/*   Updated: 2022/04/07 17:10:43 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	display_state(t_global *data, unsigned int philo_nb, enum e_state action)
{
	int	time;
	int	ret;

	if (pthread_mutex_lock(&data->print_mutex))
		return (-1);
	time = timestamp(data);
	ret = 0;
	if (time < 0)
		return (-1);
	if (action == fork_pickup)
		ret = printf("%i %u has taken a fork\n", time, philo_nb + 1);
	if (action == eating)
		ret = printf("%i %u is eating\n", time, philo_nb + 1);
	if (action == sleeping)
		ret = printf("%i %u is sleeping\n", time, philo_nb + 1);
	if (action == thinking)
		ret = printf("%i %u is thinking\n", time, philo_nb + 1);
	if (action == dead)
		ret = printf("%i %u died\n", time, philo_nb + 1);
	if (ret < 0)
		return (-1);
	if (pthread_mutex_unlock(&data->print_mutex))
		return (-1);
	return (0);
}

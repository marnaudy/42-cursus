/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 17:33:31 by marnaudy          #+#    #+#             */
/*   Updated: 2022/04/12 11:07:18 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	want_to_live(t_global *data)
{
	int	want_to_live;

	if (sem_wait(data->will_to_live_access))
		return (-1);
	want_to_live = data->will_to_live;
	if (sem_post(data->will_to_live_access))
		return (-1);
	return (want_to_live);
}

void	philo_is_happy(t_global *data)
{
	sem_post(data->philo_is_happy);
}

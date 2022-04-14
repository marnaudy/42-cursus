/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_semaphores.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 08:53:20 by marnaudy          #+#    #+#             */
/*   Updated: 2022/04/12 11:13:20 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	close_philo_sem(t_global *data)
{
	sem_close(data->last_meal_access);
	sem_close(data->will_to_live_access);
}

void	unlink_philo_sem(t_global *data, unsigned int philo_nb)
{
	char	*name;

	close_philo_sem(data);
	name = sem_name(philo_nb, last_meal);
	if (!name)
		return ;
	sem_unlink(name);
	free(name);
	name = sem_name(philo_nb, will);
	if (!name)
		return ;
	sem_unlink(name);
	free(name);
}

int	init_philo_sem(t_global *data, unsigned int philo_nb)
{
	char	*name;

	name = sem_name(philo_nb, last_meal);
	if (!name)
		return (-1);
	data->last_meal_access = sem_open(name, O_CREAT | O_EXCL, 00644, 1);
	free(name);
	name = sem_name(philo_nb, will);
	if (!name)
	{
		unlink_philo_sem(data, philo_nb);
		return (-1);
	}
	data->will_to_live_access = sem_open(name, O_CREAT | O_EXCL, 00644, 1);
	free(name);
	if (data->fork_access == SEM_FAILED
		|| data->will_to_live_access == SEM_FAILED)
	{
		unlink_philo_sem(data, philo_nb);
		return (-1);
	}
	return (0);
}

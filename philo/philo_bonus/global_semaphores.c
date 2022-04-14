/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_semaphores.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 08:36:10 by marnaudy          #+#    #+#             */
/*   Updated: 2022/04/12 16:55:56 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	close_global_sem(t_global *data)
{
	sem_close(data->forks);
	sem_close(data->fork_access);
	sem_close(data->philo_is_happy);
	sem_close(data->philo_is_dead);
	sem_close(data->end_simulation);
}

void	unlink_global_sem(t_global *data)
{
	close_global_sem(data);
	sem_unlink("philo_forks");
	sem_unlink("philo_fork_access");
	sem_unlink("philo_happy");
	sem_unlink("philo_dead");
	sem_unlink("philo_end_simul");
}

int	init_global_sem(t_global *data)
{
	data->forks
		= sem_open("philo_forks", O_CREAT | O_EXCL, 00644, data->nb_philo);
	data->fork_access
		= sem_open("philo_fork_access", O_CREAT | O_EXCL, 00644, 1);
	data->philo_is_happy
		= sem_open("philo_happy", O_CREAT | O_EXCL, 00644, 0);
	data->philo_is_dead
		= sem_open("philo_dead", O_CREAT | O_EXCL, 00644, 0);
	data->end_simulation
		= sem_open("philo_end_simul", O_CREAT | O_EXCL, 00644, 0);
	if (data->forks == SEM_FAILED
		|| data->fork_access == SEM_FAILED
		|| data->philo_is_happy == SEM_FAILED
		|| data->philo_is_dead == SEM_FAILED
		|| data->end_simulation == SEM_FAILED)
	{
		unlink_global_sem(data);
		return (-1);
	}
	return (0);
}

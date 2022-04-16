/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_semaphores.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 08:36:10 by marnaudy          #+#    #+#             */
/*   Updated: 2022/04/16 19:00:05 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	close_global_sem(t_global *data)
{
	sem_close(data->forks);
	sem_close(data->fork_access);
	sem_close(data->philo_is_happy);
	sem_close(data->philo_is_dead);
	sem_close(data->philo_is_dying);
	sem_close(data->end_simulation);
	sem_close(data->print_access);
}

void	unlink_global_sem(t_global *data)
{
	close_global_sem(data);
	sem_unlink("philo_forks");
	sem_unlink("philo_fork_access");
	sem_unlink("philo_happy");
	sem_unlink("philo_dead");
	sem_unlink("philo_dying");
	sem_unlink("philo_end_simul");
	sem_unlink("philo_print_access");
}

static void	open_global_semaphores(t_global *data)
{
	data->forks
		= sem_open("philo_forks", O_CREAT | O_EXCL, 00644, data->nb_philo);
	data->fork_access
		= sem_open("philo_fork_access", O_CREAT | O_EXCL, 00644, 1);
	data->philo_is_happy
		= sem_open("philo_happy", O_CREAT | O_EXCL, 00644, 0);
	data->philo_is_dead
		= sem_open("philo_dead", O_CREAT | O_EXCL, 00644, 0);
	data->philo_is_dying
		= sem_open("philo_dying", O_CREAT | O_EXCL, 00644, 1);
	data->end_simulation
		= sem_open("philo_end_simul", O_CREAT | O_EXCL, 00644, 0);
	data->print_access
		= sem_open("philo_print_access", O_CREAT | O_EXCL, 00644, 1);
}

int	init_global_sem(t_global *data)
{
	open_global_semaphores(data);
	if (data->forks == SEM_FAILED
		|| data->fork_access == SEM_FAILED
		|| data->philo_is_happy == SEM_FAILED
		|| data->philo_is_dead == SEM_FAILED
		|| data->philo_is_dying == SEM_FAILED
		|| data->end_simulation == SEM_FAILED
		|| data->print_access == SEM_FAILED)
	{
		unlink_global_sem(data);
		write(2, "Semaphore creation failed\n", 26);
		return (-1);
	}
	return (0);
}

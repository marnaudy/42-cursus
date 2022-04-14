/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 16:25:14 by marnaudy          #+#    #+#             */
/*   Updated: 2022/04/14 08:55:38 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	launch_processes(t_global *data)
{
	unsigned int	i;

	if (init_time(data))
		return ;
	i = 0;
	while (i < data->nb_philo)
	{
		data->pid[i] = fork();
		if (data->pid[i] == 0)
			launch_philo_threads(data, i);
		i++;
		usleep(100);
	}
	launch_main_threads(data);
	i = 0;
	while (i < data->nb_philo)
	{
		waitpid(data->pid[i], NULL, 0);
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 07:25:55 by marnaudy          #+#    #+#             */
/*   Updated: 2022/04/15 15:39:58 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int argc, char **argv)
{
	t_global	*data;

	data = parse(argc, argv);
	if (!data)
		return (1);
	if (init_global_sem(data))
	{
		free(data->pid);
		free(data);
		return (1);
	}
	launch_processes(data);
	unlink_global_sem(data);
	free(data->pid);
	free(data);
	return (0);
}

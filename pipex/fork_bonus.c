/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 21:31:21 by marnaudy          #+#    #+#             */
/*   Updated: 2022/03/17 10:53:05 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	fork_pipex(t_pipex *data)
{
	int	i;

	i = 0;
	while (i < data->nb_com)
	{
		data->pid = fork();
		if (data->pid < 0)
		{
			perror(data->name);
			return (1);
		}
		if (!data->pid)
			exec_command(data, i);
		i++;
	}
	return (0);
}

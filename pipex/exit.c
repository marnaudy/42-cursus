/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 21:24:02 by marnaudy          #+#    #+#             */
/*   Updated: 2022/03/16 21:08:31 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	free_exec(t_command *exec, int n)
{
	int	i;
	int	j;

	if (exec)
	{
		i = 0;
		while (i < n)
		{
			if (exec[i].path != exec[i].args[0])
				free(exec[i].path);
			if (exec[i].args)
			{
				j = 0;
				while (exec[i].args[j])
				{
					free(exec[i].args[j]);
					j++;
				}
				free(exec[i].args);
			}
			i++;
		}
		free(exec);
	}
}

void	close_pipex(t_pipex *data, int ret)
{
	if (data)
	{
		free_exec(data->exec, data->nb_com);
		free(data->filenames);
		free(data->pipe_fd);
		free(data);
	}
	exit(ret);
}

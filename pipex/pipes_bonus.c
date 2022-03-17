/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 21:20:07 by marnaudy          #+#    #+#             */
/*   Updated: 2022/03/16 16:16:22 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	close_pipes(t_pipex *data, int n)
{
	int	i;
	int	nb_to_close;

	if (n < 0)
		nb_to_close = data->nb_com - !data->limiter;
	else
		nb_to_close = n;
	i = 0;
	while (i < nb_to_close)
	{
		if (close(data->pipe_fd[2 * i])
			|| close(data->pipe_fd[2 * i + 1]))
		{
			perror(data->name);
			close_pipex(data, 127);
		}
		i++;
	}
}

void	open_pipes(t_pipex *data)
{
	int	i;

	i = 0;
	while (i < data->nb_com - !data->limiter)
	{
		if (pipe(data->pipe_fd + i * 2))
		{
			perror(data->name);
			close_pipes(data, i);
			close_pipex(data, 127);
		}
		i++;
	}
}

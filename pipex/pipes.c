/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 21:20:07 by marnaudy          #+#    #+#             */
/*   Updated: 2022/03/16 21:17:11 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_pipe(t_pipex *data)
{
	if (close(data->pipe_fd[0])
		|| close(data->pipe_fd[1]))
	{
		perror(data->name);
		close_pipex(data, 127);
	}
}

void	open_pipe(t_pipex *data)
{
	if (pipe(data->pipe_fd))
	{
		perror(data->name);
		close_pipex(data, 127);
	}
}

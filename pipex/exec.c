/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 20:54:41 by marnaudy          #+#    #+#             */
/*   Updated: 2022/03/16 21:16:31 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	duplicate_in(t_pipex *data, int n)
{
	int	fd;

	if (n == 0)
		fd = open_infile(data);
	else
		fd = data->pipe_fd[n * 2 - 2];
	if (dup2(fd, STDIN_FILENO) != STDIN_FILENO)
	{
		perror(data->name);
		if (n == 0)
			close(fd);
		close_pipe(data);
		close_pipex(data, 127);
	}
	if (n == 0 && close(fd))
	{
		perror(data->name);
		close_pipe(data);
		close_pipex(data, 127);
	}
}

static void	duplicate_out(t_pipex *data, int n)
{
	int	fd;

	if (n == data->nb_com - 1)
		fd = open_outfile(data);
	else
		fd = data->pipe_fd[n * 2 + 1];
	if (dup2(fd, STDOUT_FILENO) != STDOUT_FILENO)
	{
		perror(data->name);
		close(fd);
		close_pipe(data);
		close_pipex(data, 127);
	}
	if (n == data->nb_com - 1 && close(fd))
	{
		perror(data->name);
		close_pipe(data);
		close_pipex(data, 127);
	}
}

void	exec_command(t_pipex *data, int n)
{
	duplicate_in(data, n);
	duplicate_out(data, n);
	close_pipe(data);
	find_exec(data, n);
	if (execve(data->exec[n].path, data->exec[n].args, data->envp) == -1)
	{
		ft_putstr_fd(data->name, ": ", STDERR_FILENO);
		perror(data->exec[n].args[0]);
	}
	close_pipex(data, 127);
}

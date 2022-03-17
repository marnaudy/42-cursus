/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:43:38 by marnaudy          #+#    #+#             */
/*   Updated: 2022/03/16 19:28:10 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	open_infile(t_pipex *data)
{
	int	fd;

	if (data->limiter)
		return (data->pipe_fd[data->nb_com * 2 - 2]);
	fd = open(data->filenames[0], O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd(data->name, ": ", STDERR_FILENO);
		perror(data->filenames[0]);
		close_pipes(data, -1);
		close_pipex(data, 1);
	}
	return (fd);
}

int	open_outfile(t_pipex *data)
{
	int	fd;

	if (data->limiter)
		fd = open(data->filenames[1], O_WRONLY | O_CREAT | O_APPEND, 00644);
	else
		fd = open(data->filenames[1], O_WRONLY | O_CREAT | O_TRUNC, 00644);
	if (fd < 0)
	{
		ft_putstr_fd(data->name, ": ", STDERR_FILENO);
		perror(data->filenames[1]);
		close_pipes(data, -1);
		close_pipex(data, 1);
	}
	return (fd);
}

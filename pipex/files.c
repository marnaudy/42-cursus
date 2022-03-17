/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:43:38 by marnaudy          #+#    #+#             */
/*   Updated: 2022/03/16 21:18:13 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	open_infile(t_pipex *data)
{
	int	fd;

	fd = open(data->filenames[0], O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd(data->name, ": ", STDERR_FILENO);
		perror(data->filenames[0]);
		close_pipe(data);
		close_pipex(data, 1);
	}
	return (fd);
}

int	open_outfile(t_pipex *data)
{
	int	fd;

	fd = open(data->filenames[1], O_WRONLY | O_CREAT | O_TRUNC, 00644);
	if (fd < 0)
	{
		ft_putstr_fd(data->name, ": ", STDERR_FILENO);
		perror(data->filenames[1]);
		close_pipe(data);
		close_pipex(data, 1);
	}
	return (fd);
}

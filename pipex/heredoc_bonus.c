/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 19:37:10 by marnaudy          #+#    #+#             */
/*   Updated: 2022/03/16 21:34:53 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	malloc_error(t_pipex *data)
{
	perror(data->name);
	close_pipex(data, 127);
}

static void	no_delimiter(t_pipex *data)
{
	ft_putstr_fd(data->name,
		": warning: here-document delimited by end-of-file (wanted '",
		STDERR_FILENO);
	ft_putstr_fd(data->limiter, "')\n", STDERR_FILENO);
}

static int	eof_heredoc(char *input, char *delimiter)
{
	if (!ft_strcmp(input, delimiter))
	{
		free(input);
		return (1);
	}
	if (input[ft_strlen(input) - 1] == '\n')
	{
		input[ft_strlen(input) - 1] = 0;
		if (!ft_strcmp(input, delimiter))
		{
			free(input);
			return (1);
		}
		input[ft_strlen(input)] = '\n';
	}
	return (0);
}

void	read_heredoc(t_pipex *data)
{
	char	*input;
	char	*old_heredoc;
	int		gnl_code;

	while (1)
	{
		input = get_next_line(STDIN_FILENO, &gnl_code);
		if (gnl_code)
			malloc_error(data);
		if (!input)
		{
			no_delimiter(data);
			return ;
		}
		if (eof_heredoc(input, data->limiter))
			return ;
		old_heredoc = data->here_doc;
		data->here_doc = ft_strcat(old_heredoc, input);
		free(old_heredoc);
		free(input);
		if (!data->here_doc)
			malloc_error(data);
	}
}

void	write_heredoc(t_pipex *data)
{
	write(data->pipe_fd[data->nb_com * 2 - 1],
		data->here_doc,
		ft_strlen(data->here_doc));
	free(data->here_doc);
	data->here_doc = NULL;
}

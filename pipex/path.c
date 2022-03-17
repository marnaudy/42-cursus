/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 17:04:03 by marnaudy          #+#    #+#             */
/*   Updated: 2022/03/16 21:13:49 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	contains_slash(char	*name)
{
	int	i;

	if (!name)
		return (0);
	i = 0;
	while (name[i])
	{
		if (name[i] == '/')
			return (1);
		i++;
	}
	return (0);
}

static int	find_path_line(char **envp)
{
	int	idx;

	if (!envp)
		return (-1);
	idx = 0;
	while (envp[idx])
	{
		if (!ft_strncmp(envp[idx], "PATH=", 5) && ft_strlen(envp[idx]) > 5)
			return (idx);
		idx++;
	}
	return (-1);
}

void	find_exec(t_pipex *data, int n)
{
	int	path_line;

	path_line = find_path_line(data->envp);
	if (contains_slash(data->exec[n].args[0]) || path_line < 0)
	{
		data->exec[n].path = data->exec[n].args[0];
		if (access(data->exec[n].path, X_OK))
		{
			ft_putstr_fd(data->name, ": ", STDERR_FILENO);
			perror(data->exec[n].path);
			close_pipex(data, 126);
		}
		else
			return ;
	}
	search_path(data, n, path_line);
}

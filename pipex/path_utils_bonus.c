/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 17:12:51 by marnaudy          #+#    #+#             */
/*   Updated: 2022/03/16 19:16:16 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	free_char_array(char **arr)
{
	int	i;

	if (arr)
	{
		i = 0;
		while (arr[i])
		{
			free(arr[i]);
			i++;
		}
		free(arr);
	}
}

static void	cmd_not_found(t_pipex *data, int cmd_nb)
{
	ft_putstr_fd(data->name, ": ", STDERR_FILENO);
	ft_putstr_fd(data->exec[cmd_nb].args[0],
		": command not found\n", STDERR_FILENO);
	close_pipex(data, 127);
}

void	search_path(t_pipex *data, int n, int path_line)
{
	char	**arr;
	int		i;

	arr = ft_split(data->envp[path_line], ':');
	if (!arr)
	{
		perror(data->name);
		close_pipex(data, 127);
	}
	i = 0;
	while (arr[i])
	{
		free(data->exec[n].path);
		data->exec[n].path = ft_strcat_slash(arr[i], data->exec[n].args[0]);
		if (!data->exec[n].path || !access(data->exec[n].path, X_OK))
		{
			free_char_array(arr);
			return ;
		}
		i++;
	}
	free_char_array(arr);
	cmd_not_found(data, n);
}

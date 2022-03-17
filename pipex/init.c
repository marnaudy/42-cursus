/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 22:25:56 by marnaudy          #+#    #+#             */
/*   Updated: 2022/03/16 21:10:05 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	*ft_calloc(int nmemb, int size)
{
	void	*new;
	int		i;

	new = malloc(nmemb * size);
	if (!new)
		return (NULL);
	i = 0;
	while (i < nmemb * size)
	{
		((char *)new)[i] = 0;
		i++;
	}
	return (new);
}

t_pipex	*init(int n, char *name)
{
	t_pipex	*data;

	data = malloc(sizeof(t_pipex));
	if (!data)
	{
		perror(name);
		close_pipex(NULL, 1);
	}
	data->nb_com = n;
	data->name = name;
	data->exec = ft_calloc(n, sizeof(t_command));
	data->filenames = ft_calloc(2, sizeof(char *));
	data->pipe_fd = ft_calloc(n * 2, sizeof(int));
	if (!data->exec || !data->filenames || !data->pipe_fd)
	{
		perror(name);
		close_pipex(data, 127);
	}
	return (data);
}

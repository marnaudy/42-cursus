/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 22:50:23 by marnaudy          #+#    #+#             */
/*   Updated: 2022/03/16 21:12:40 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	split_args(t_pipex *data, int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < data->nb_com && (i + 2 + !!data->limiter) < argc)
	{
		data->exec[i].args = ft_split(argv[i + 2 + !!data->limiter], ' ');
		if (!data->exec[i].args)
		{
			perror(data->name);
			close_pipex(data, 127);
		}
		i++;
	}
}

static void	too_few_args(char *name)
{
	ft_putstr_fd(name, ": too few arguments\n", STDERR_FILENO);
	close_pipex(NULL, 1);
}

t_pipex	*parse(int argc, char **argv)
{
	t_pipex	*data;

	if (argc < 5)
		too_few_args(argv[0]);
	if (ft_strcmp(argv[1], "here_doc"))
	{
		data = init(argc - 3, argv[0]);
		data->nb_com = argc - 3;
		data->filenames[0] = argv[1];
	}
	else
	{
		if (argc < 6)
			too_few_args(argv[0]);
		data = init(argc - 4, argv[0]);
		data->nb_com = argc - 4;
		data->limiter = argv[2];
	}
	data->filenames[1] = argv[argc - 1];
	split_args(data, argc, argv);
	return (data);
}

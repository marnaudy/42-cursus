/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 22:50:23 by marnaudy          #+#    #+#             */
/*   Updated: 2022/03/16 21:23:28 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	split_args(t_pipex *data, int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < data->nb_com && (i + 2) < argc)
	{
		data->exec[i].args = ft_split(argv[i + 2], ' ');
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

static void	too_many_args(char *name)
{
	ft_putstr_fd(name, ": too many arguments\n", STDERR_FILENO);
	close_pipex(NULL, 1);
}

t_pipex	*parse(int argc, char **argv)
{
	t_pipex	*data;

	if (argc < 5)
		too_few_args(argv[0]);
	if (argc > 5)
		too_many_args(argv[0]);
	data = init(argc - 3, argv[0]);
	data->nb_com = argc - 3;
	data->filenames[0] = argv[1];
	data->filenames[1] = argv[argc - 1];
	split_args(data, argc, argv);
	return (data);
}

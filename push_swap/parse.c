/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 16:33:01 by marnaudy          #+#    #+#             */
/*   Updated: 2021/12/17 17:10:49 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap_utils.h"

static int	is_duplicate(t_push_swap *data, int nb_to_check)
{
	int	i;

	i = 0;
	while (i < data->a_size)
	{
		if (data->a[i] == nb_to_check)
			return (1);
		i++;
	}
	return (0);
}

static int	strict_atoi(char *str, int *res)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	*res = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (*res > 214748365
			|| (*res == 214748364 && str[i] > ('7' + (sign == -1))))
			return (1);
		*res = *res * 10 + str[i] - '0';
		i++;
	}
	*res = *res * sign;
	if (str[i] || i == 0)
		return (1);
	return (0);
}

static int	read_arg(t_push_swap *data, char *arg)
{
	int			nb;

	if (strict_atoi(arg, &nb) || is_duplicate(data, nb))
		return (1);
	data->a[data->a_size] = nb;
	data->a_size++;
	return (0);
}

static t_push_swap	*init_struct(int argc)
{
	t_push_swap	*data;

	data = malloc(sizeof(t_push_swap));
	if (data == NULL)
		return (NULL);
	data->a = malloc(sizeof(int) * (argc - 1));
	data->b = malloc(sizeof(int) * (argc - 1));
	data->cost = malloc(sizeof(t_cost) * (argc - 1));
	if (data->a == NULL || data->b == NULL || data->cost == NULL)
	{
		free_everything(data);
		return (NULL);
	}
	data->a_size = 0;
	data->b_size = 0;
	data->instr_begin = NULL;
	data->instr_end = NULL;
	return (data);
}

t_push_swap	*parse(int argc, char **argv)
{
	t_push_swap	*data;
	int			i;

	if (argc < 2)
		return (NULL);
	data = init_struct(argc);
	if (!data)
		return (NULL);
	i = argc - 1;
	while (i != 0)
	{
		if (read_arg(data, argv[i]))
		{
			free_everything(data);
			return (NULL);
		}
		i--;
	}
	return (data);
}

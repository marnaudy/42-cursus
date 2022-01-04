/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:36:18 by marnaudy          #+#    #+#             */
/*   Updated: 2021/12/17 17:09:52 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "push_swap_utils.h"

void	free_everything(t_push_swap *data)
{
	void	*to_free;

	while (data->instr_begin)
	{
		to_free = (void *)data->instr_begin;
		data->instr_begin = data->instr_begin->next;
		free(to_free);
	}
	free(data->a);
	free(data->b);
	free(data->cost);
	free(data);
}

static void	ft_putstr_nl(char *str)
{
	int	size;

	size = 0;
	while (str[size])
		size++;
	write(1, str, size);
	write(1, "\n", 1);
}

static char	*move_to_str(int move)
{
	if (move == sa)
		return ("sa");
	if (move == sb)
		return ("sb");
	if (move == ss)
		return ("ss");
	if (move == pa)
		return ("pa");
	if (move == pb)
		return ("pb");
	if (move == ra)
		return ("ra");
	if (move == rb)
		return ("rb");
	if (move == rr)
		return ("rr");
	if (move == rra)
		return ("rra");
	if (move == rrb)
		return ("rrb");
	if (move == rrr)
		return ("rrr");
	return ("");
}

void	display_instructions(t_push_swap *data)
{
	t_instr	*instr_link;

	instr_link = data->instr_begin;
	while (instr_link)
	{
		ft_putstr_nl(move_to_str(instr_link->move));
		instr_link = instr_link->next;
	}
}

int	is_sorted_a(t_push_swap *data)
{
	int	i;

	i = 0;
	while (i < data->a_size - 1)
	{
		if (data->a[i + 1] > data->a[i])
			return (0);
		i++;
	}
	return (1);
}

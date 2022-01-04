/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:12:36 by marnaudy          #+#    #+#             */
/*   Updated: 2021/12/13 22:46:25 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "move_utils.h"

static int	add_instr(t_push_swap *data, int move)
{
	t_instr	*new_instr;

	new_instr = malloc(sizeof(t_instr));
	if (!new_instr)
		return (1);
	new_instr->move = move;
	new_instr->next = NULL;
	if (!data->instr_begin)
	{
		data->instr_begin = new_instr;
		data->instr_end = new_instr;
	}
	else
	{
		data->instr_end->next = new_instr;
		data->instr_end = new_instr;
	}
	return (0);
}

static void	exec_move(t_push_swap *data, int move)
{
	if (move == 0)
		exec_sa(data);
	if (move == 1)
		exec_sb(data);
	if (move == 2)
		exec_ss(data);
	if (move == 3)
		exec_pa(data);
	if (move == 4)
		exec_pb(data);
	if (move == 5)
		exec_ra(data);
	if (move == 6)
		exec_rb(data);
	if (move == 7)
		exec_rr(data);
	if (move == 8)
		exec_rra(data);
	if (move == 9)
		exec_rrb(data);
	if (move == 10)
		exec_rrr(data);
}

int	move(t_push_swap *data, int move, int nb)
{
	int	i;

	i = 0;
	while (i < nb)
	{
		if (add_instr(data, move))
			return (1);
		i++;
	}
	i = 0;
	while (i < nb)
	{
		exec_move(data, move);
		i++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 10:58:04 by marnaudy          #+#    #+#             */
/*   Updated: 2021/12/23 12:40:58 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "insert_utils.h"
#include "move.h"

static int	rotate(t_push_swap *data, int rot_a, int rot_b)
{
	int	ret;

	ret = 0;
	ret += move(data, rr, min(rot_a, rot_b));
	if (rot_a > rot_b)
		ret += move(data, ra, rot_a - rot_b);
	else
		ret += move(data, rb, rot_b - rot_a);
	return (ret);
}

static int	rev_rotate(t_push_swap *data, int rot_a, int rot_b)
{
	int	ret;

	ret = 0;
	ret += move(data, rrr, min(rot_a, rot_b));
	if (rot_a > rot_b)
		ret += move(data, rra, rot_a - rot_b);
	else
		ret += move(data, rrb, rot_b - rot_a);
	return (ret);
}

static int	prepare_insert(t_push_swap *data, t_cost *cost)
{
	int	ret;

	if (max(cost->ra, cost->rb) == cost->min)
		return (rotate(data, cost->ra, cost->rb));
	if (max(cost->rra, cost->rrb) == cost->min)
		return (rev_rotate(data, cost->rra, cost->rrb));
	ret = 0;
	if (min(cost->ra, cost->rra) == cost->ra)
		ret += rotate(data, cost->ra, 0);
	else
		ret += rev_rotate(data, cost->rra, 0);
	if (min(cost->rb, cost->rrb) == cost->rb)
		ret += rotate(data, 0, cost->rb);
	else
		ret += rev_rotate(data, 0, cost->rrb);
	return (ret);
}

int	insert(t_push_swap *data)
{
	int		index;
	int		ret;
	t_cost	*cost;

	index = find_cheapest(data);
	cost = &data->cost[index];
	ret = 0;
	ret += prepare_insert(data, cost);
	ret += move(data, pa, 1);
	return (ret);
}

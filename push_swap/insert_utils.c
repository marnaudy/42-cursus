/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 17:32:06 by marnaudy          #+#    #+#             */
/*   Updated: 2021/12/23 12:30:16 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "search.h"

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	triple_min(int a, int b, int c)
{
	if (a < b && a < c)
		return (a);
	if (b < c)
		return (b);
	return (c);
}

static void	calculate_cost(t_push_swap *data, int idx_b)
{
	int		idx_a;
	t_cost	*cost;

	cost = &data->cost[idx_b];
	idx_a = find_one_bigger_a(data, data->b[idx_b]);
	cost->ra = data->a_size - idx_a - 1;
	cost->rb = data->b_size - idx_b - 1;
	cost->rra = idx_a + 1;
	cost->rrb = idx_b + 1;
	cost->min = triple_min(
			min(cost->ra, cost->rra) + min(cost->rb, cost->rrb),
			max(cost->ra, cost->rb),
			max(cost->rra, cost->rrb));
}

int	find_cheapest(t_push_swap *data)
{
	int	i;
	int	min_cost;
	int	cheap_index;

	calculate_cost(data, 0);
	min_cost = data->cost[0].min;
	cheap_index = 0;
	i = 1;
	while (i < data->b_size)
	{
		calculate_cost(data, i);
		if (data->cost[i].min < min_cost)
		{
			min_cost = data->cost[i].min;
			cheap_index = i;
		}
		i++;
	}
	return (cheap_index);
}

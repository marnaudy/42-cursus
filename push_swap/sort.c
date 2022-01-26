/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 22:24:40 by marnaudy          #+#    #+#             */
/*   Updated: 2022/01/26 13:18:50 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "search.h"
#include "insert.h"
#include "move.h"
#include "longest_increasing_subsequence.h"

static int	sort_3(t_push_swap *data)
{
	int	ret;

	ret = 0;
	if (is_sorted_a(data))
		return (ret);
	if (find_largest_a(data) == 1)
		ret += move(data, rra, 1);
	if (is_sorted_a(data))
		return (ret);
	if (find_largest_a(data) == 0)
		ret += move(data, sa, 1);
	if (is_sorted_a(data))
		return (ret);
	if (find_smallest_a(data) == 1)
		ret += move(data, ra, 1);
	else
	{
		ret += move(data, sa, 1);
		ret += move(data, rra, 1);
	}
	return (ret);
}

static int	smallest_to_top(t_push_swap *data)
{
	int	small_idx;

	small_idx = find_smallest_sorted_a(data);
	if (small_idx < data->a_size / 2)
		return (move(data, rra, small_idx + 1));
	else
		return (move(data, ra, data->a_size - small_idx - 1));
}

static int	sort_small(t_push_swap *data)
{
	int	ret;

	ret = 0;
	if (move(data, pb, data->a_size - 3))
		return (1);
	ret += sort_3(data);
	while (data->b_size && !ret)
		ret += insert(data);
	ret += smallest_to_top(data);
	return (ret);
}

static int	push_to_b(t_push_swap *data)
{
	int	i;
	int	a_size;
	int	*lis;
	int	lis_size;
	int	ret;

	a_size = data->a_size;
	ret = 0;
	lis_size = find_lis(data, &lis);
	if (lis_size < 0)
		return (1);
	i = 0;
	while (i < a_size)
	{
		if (is_in_lis(lis, lis_size, data->a[data->a_size - 1]))
			ret += move(data, ra, 1);
		else
			ret += move(data, pb, 1);
		i++;
	}
	free(lis);
	return (ret);
}

int	sort(t_push_swap *data)
{
	int		ret;

	ret = 0;
	if (data->a_size <= 3)
		return (sort_3(data));
	if (data->a_size <= 10)
		return (sort_small(data));
	ret += push_to_b(data);
	while (data->b_size && !ret)
		ret += insert(data);
	ret += smallest_to_top(data);
	return (ret);
}

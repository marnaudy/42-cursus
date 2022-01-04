/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 22:24:40 by marnaudy          #+#    #+#             */
/*   Updated: 2021/12/23 13:21:36 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_utils.h"
#include "search.h"
#include "insert.h"
#include "move.h"

static int	smallest_to_top(t_push_swap *data)
{
	int	small_idx;

	small_idx = find_smallest_sorted_a(data);
	if (small_idx < data->a_size / 2)
		return (move(data, rra, small_idx + 1));
	else
		return (move(data, ra, data->a_size - small_idx - 1));
}

int	sort(t_push_swap *data)
{
	int		ret;

	ret = 0;
	if (move(data, pb, data->a_size - 3))
		return (1);
	ret += sort_3(data);
	while (data->b_size)
		ret += insert(data);
	ret += smallest_to_top(data);
	return (ret);
}

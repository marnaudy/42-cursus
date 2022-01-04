/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 15:30:53 by marnaudy          #+#    #+#             */
/*   Updated: 2021/12/13 22:52:27 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "search.h"
#include "move.h"

int	sort_3(t_push_swap *data)
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

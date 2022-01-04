/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 21:35:30 by marnaudy          #+#    #+#             */
/*   Updated: 2021/12/23 12:39:57 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

int	find_smallest_a(t_push_swap *data)
{
	int	i;
	int	smallest;
	int	idx_smallest;

	if (data->a_size == 0)
		return (-1);
	smallest = data->a[0];
	idx_smallest = 0;
	i = 1;
	while (i < data->a_size)
	{
		if (data->a[i] < smallest)
		{
			smallest = data->a[i];
			idx_smallest = i;
		}
		i++;
	}
	return (idx_smallest);
}

int	find_largest_a(t_push_swap *data)
{
	int	i;
	int	largest;
	int	idx_largest;

	if (data->a_size == 0)
		return (-1);
	largest = data->a[0];
	idx_largest = 0;
	i = 1;
	while (i < data->a_size)
	{
		if (data->a[i] > largest)
		{
			largest = data->a[i];
			idx_largest = i;
		}
		i++;
	}
	return (idx_largest);
}

int	find_smallest_sorted_a(t_push_swap *data)
{
	int	i;
	int	top;

	if (data->a_size == 0)
		return (-1);
	top = data->a[data->a_size - 1];
	i = data->a_size - 2;
	while (i >= 0)
	{
		if (data->a[i] < top)
			return (i);
		i--;
	}
	return (data->a_size - 1);
}

int	find_one_bigger_a(t_push_swap *data, int nb)
{
	int	i;
	int	idx_smallest;

	if (data->a_size == 0)
		return (-1);
	idx_smallest = find_smallest_sorted_a(data);
	i = idx_smallest;
	if (data->a[i] > nb)
		return (i);
	while (1)
	{
		if (i == 0)
			i = data->a_size;
		i--;
		if (i == idx_smallest || data->a[i] > nb)
			return (i);
	}
}

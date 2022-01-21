/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longest_increasing_subsequence.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 20:28:13 by marnaudy          #+#    #+#             */
/*   Updated: 2022/01/06 18:58:09 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap_utils.h"

static int	*calculate_lis_len_arr(t_push_swap *data)
{
	int	*len_arr;
	int	i;
	int	j;
	int	max;

	len_arr = malloc(sizeof(int) * data->a_size);
	if (!len_arr)
		return (NULL);
	i = 0;
	while (i < data->a_size)
	{
		j = 0;
		max = 0;
		while (j < i)
		{
			if (len_arr[j] > max && data->a[j] < data->a[i])
				max = len_arr[j];
			j++;
		}
		len_arr[i] = max + 1;
		i++;
	}
	return (len_arr);
}

static int	calculate_lis_len(int *len_arr, int arr_size)
{
	int	i;
	int	max;

	i = 0;
	max = 0;
	while (i < arr_size)
	{
		if (len_arr[i] > max)
			max = len_arr[i];
		i++;
	}
	return (max);
}

int	is_in_lis(int *lis, int size, int nb)
{
	if (size == 0)
		return (0);
	if (lis[size / 2] == nb)
		return (1);
	if (lis[size / 2] < nb)
		return (is_in_lis(lis + size / 2 + 1, size - size / 2 - 1, nb));
	if (lis[size / 2] > nb)
		return (is_in_lis(lis, size / 2, nb));
}

int	find_lis(t_push_swap *data, int	**lis)
{
	int	*len_arr;
	int	lis_len;

	len_arr = calculate_lis_len_arr(data);
	if (!len_arr)
		return (-1);
	lis_len = calculate_lis_len(len_arr, data->a_size);
	*lis = malloc(sizeof(int) * lis_len);
	if (!*lis)
	{
		free(len_arr);
		return (-1);
	}
	free(len_arr);
	return (lis_len);
}

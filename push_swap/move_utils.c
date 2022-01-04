/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 19:07:49 by marnaudy          #+#    #+#             */
/*   Updated: 2021/12/23 14:21:46 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

void	exec_sa(t_push_swap *data)
{
	int	temp;
	int	size;

	size = data->a_size;
	if (size <= 1)
		return ;
	temp = data->a[size - 1];
	data->a[size - 1] = data->a[size - 2];
	data->a[size - 2] = temp;
}

void	exec_sb(t_push_swap *data)
{
	int	temp;
	int	size;

	size = data->b_size;
	if (size <= 1)
		return ;
	temp = data->b[size - 1];
	data->b[size - 1] = data->b[size - 2];
	data->b[size - 2] = temp;
}

void	exec_ss(t_push_swap *data)
{
	exec_sa(data);
	exec_sb(data);
}

void	exec_pa(t_push_swap *data)
{
	if (data->b_size == 0)
		return ;
	data->a[data->a_size] = data->b[data->b_size - 1];
	data->a_size++;
	data->b_size--;
}

void	exec_pb(t_push_swap *data)
{
	if (data->a_size == 0)
		return ;
	data->b[data->b_size] = data->a[data->a_size - 1];
	data->a_size--;
	data->b_size++;
}

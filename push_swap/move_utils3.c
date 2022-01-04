/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 19:27:46 by marnaudy          #+#    #+#             */
/*   Updated: 2021/12/23 14:23:06 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

void	exec_rra(t_push_swap *data)
{
	int	temp;
	int	i;

	if (data->a_size <= 1)
		return ;
	i = 0;
	temp = data->a[i];
	while (i != data->a_size - 1)
	{
		data->a[i] = data->a[i + 1];
		i++;
	}
	data->a[i] = temp;
}

void	exec_rrb(t_push_swap *data)
{
	int	temp;
	int	i;

	if (data->b_size <= 1)
		return ;
	i = 0;
	temp = data->b[i];
	while (i != data->b_size - 1)
	{
		data->b[i] = data->b[i + 1];
		i++;
	}
	data->b[i] = temp;
}

void	exec_rrr(t_push_swap *data)
{
	exec_rra(data);
	exec_rrb(data);
}

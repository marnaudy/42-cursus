/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 19:21:08 by marnaudy          #+#    #+#             */
/*   Updated: 2021/12/23 14:22:44 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

void	exec_ra(t_push_swap *data)
{
	int	temp;
	int	i;

	if (data->a_size <= 1)
		return ;
	i = data->a_size - 1;
	temp = data->a[i];
	while (i != 0)
	{
		data->a[i] = data->a[i - 1];
		i--;
	}
	data->a[0] = temp;
}

void	exec_rb(t_push_swap *data)
{
	int	temp;
	int	i;

	if (data->b_size <= 1)
		return ;
	i = data->b_size - 1;
	temp = data->b[i];
	while (i != 0)
	{
		data->b[i] = data->b[i - 1];
		i--;
	}
	data->b[0] = temp;
}

void	exec_rr(t_push_swap *data)
{
	exec_ra(data);
	exec_rb(data);
}

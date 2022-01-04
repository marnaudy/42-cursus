/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 22:23:04 by marnaudy          #+#    #+#             */
/*   Updated: 2021/12/16 16:12:46 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap_utils.h"

static int	print_error(void)
{
	write(2, "Error\n", 6);
	return (1);
}

int	main(int argc, char **argv)
{
	t_push_swap	*data;

	data = parse(argc, argv);
	if (data == 0)
		return (print_error());
	if (!is_sorted_a(data) && sort(data))
	{
		free_everything(data);
		return (print_error());
	}
	display_instructions(data);
	free_everything(data);
	return (0);
}

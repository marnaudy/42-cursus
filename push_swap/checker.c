/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 15:58:11 by marnaudy          #+#    #+#             */
/*   Updated: 2021/12/23 18:18:00 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"
#include "push_swap_utils.h"
#include "move.h"

static int	print_error(void)
{
	write(2, "Error\n", 6);
	return (1);
}

static int	str_to_move(char *str)
{
	if (str[0] == 'p' && str[1] == 'a' && str[2] == '\n')
		return (pa);
	if (str[0] == 'p' && str[1] == 'b' && str[2] == '\n')
		return (pb);
	if (str[0] == 's' && str[1] == 'a' && str[2] == '\n')
		return (sa);
	if (str[0] == 's' && str[1] == 'b' && str[2] == '\n')
		return (sb);
	if (str[0] == 's' && str[1] == 's' && str[2] == '\n')
		return (ss);
	if (str[0] == 'r' && str[1] == 'a' && str[2] == '\n')
		return (ra);
	if (str[0] == 'r' && str[1] == 'b' && str[2] == '\n')
		return (rb);
	if (str[0] == 'r' && str[1] == 'r' && str[2] == '\n')
		return (rr);
	if (str[0] == 'r' && str[1] == 'r' && str[2] == 'a' && str[3] == '\n')
		return (rra);
	if (str[0] == 'r' && str[1] == 'r' && str[2] == 'b' && str[3] == '\n')
		return (rrb);
	if (str[0] == 'r' && str[1] == 'r' && str[2] == 'r' && str[3] == '\n')
		return (rrr);
	return (-1);
}

int	main(int argc, char **argv)
{
	t_push_swap	*data;
	char		*instr;
	int			move_nb;

	data = parse(argc, argv);
	if (data == 0)
		return (print_error());
	instr = get_next_line(STDIN_FILENO);
	while (instr)
	{
		move_nb = str_to_move(instr);
		free(instr);
		if (move_nb == -1)
			return (print_error());
		if (move(data, move_nb, 1))
			return (1);
		instr = get_next_line(STDIN_FILENO);
	}
	if (is_sorted_a(data) && data->b_size == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_everything(data);
	return (0);
}

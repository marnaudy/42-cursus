/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 16:26:40 by marnaudy          #+#    #+#             */
/*   Updated: 2022/01/26 12:00:05 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_UTILS_H
# define PUSH_SWAP_UTILS_H

enum	e_moves
{
	sa,
	sb,
	ss,
	pa,
	pb,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr
};

typedef struct s_instr
{
	int				move;
	struct s_instr	*next;
}	t_instr;

typedef struct s_cost
{
	int	ra;
	int	rb;
	int	rra;
	int	rrb;
	int	min;
}	t_cost;

typedef struct s_push_swap
{
	int		*a;
	int		*b;
	int		a_size;
	int		b_size;
	t_cost	*cost;
	t_instr	*instr_begin;
	t_instr	*instr_end;
}	t_push_swap;

void		free_everything(t_push_swap *data);
void		display_instructions(t_push_swap *data);
t_push_swap	*parse(int argc, char **argv);
int			is_sorted_a(t_push_swap *data);
int			sort(t_push_swap *data);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 21:59:06 by marnaudy          #+#    #+#             */
/*   Updated: 2021/12/13 22:11:36 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEARCH_H
# define SEARCH_H
# include "push_swap_utils.h"

int	find_smallest_a(t_push_swap *data);
int	find_largest_a(t_push_swap *data);
int	find_smallest_sorted_a(t_push_swap *data);
int	find_one_bigger_a(t_push_swap *data, int nb);

#endif

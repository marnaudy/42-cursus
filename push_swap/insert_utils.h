/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 10:55:18 by marnaudy          #+#    #+#             */
/*   Updated: 2021/12/23 10:56:50 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSERT_UTILS_H
# define INSERT_UTILS_H

# include "push_swap_utils.h"

int	max(int a, int b);
int	min(int a, int b);
int	triple_min(int a, int b, int c);
int	find_cheapest(t_push_swap *data);

#endif

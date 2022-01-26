/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longest_increasing_subsequence.h                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 20:27:35 by marnaudy          #+#    #+#             */
/*   Updated: 2022/01/21 16:26:48 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LONGEST_INCREASING_SUBSEQUENCE_H
# define LONGEST_INCREASING_SUBSEQUENCE_H

# include "push_swap_utils.h"

int	is_in_lis(int *lis, int size, int nb);
int	find_lis(t_push_swap *data, int **lis);

#endif

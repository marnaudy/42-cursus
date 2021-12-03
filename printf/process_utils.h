/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_utils.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 10:55:46 by marnaudy          #+#    #+#             */
/*   Updated: 2021/12/03 07:26:58 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROCESS_UTILS_H
# define PROCESS_UTILS_H

void	ft_add_sign(t_tag *tag);
void	ft_add_precision(t_tag *tag);
void	ft_add_padding(t_tag *tag);
char	*ft_utoa_base(unsigned long int n, char *base);
void	ft_process_c(t_tag *tag);
void	ft_process_str(t_tag *tag);
void	ft_process_int(t_tag *tag);
void	ft_process_unsigned_int(t_tag *tag);
void	ft_process_hex(t_tag *tag);
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 08:50:59 by marnaudy          #+#    #+#             */
/*   Updated: 2021/12/03 07:47:00 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_UTILS_H
# define PRINTF_UTILS_H
# include <stdarg.h>

typedef struct s_tag
{
	char	*text;
	void	*data;
	int		is_tag;
	int		width;
	int		precision;
	int		align_left;
	char	padding;
	int		prefix;
	char	sign;
	char	specifier;
}	t_tag;

void	ft_free_array(t_tag *array, int size);
void	ft_display(t_tag *array, int size);
int		ft_parse_format(const char *str, t_tag **array);
int		ft_count_char(t_tag *array, int size);
void	ft_process_tags(t_tag *array, int size);
void	ft_assign_content(t_tag *array, int size, va_list args);
#endif

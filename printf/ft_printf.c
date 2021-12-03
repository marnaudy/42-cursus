/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 17:12:48 by marnaudy          #+#    #+#             */
/*   Updated: 2021/12/03 06:09:45 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "printf_utils.h"

int	ft_printf(const char *format_str, ...)
{
	t_tag	*array;
	int		arr_size;
	int		printed_char;
	va_list	args;

	arr_size = ft_parse_format(format_str, &array);
	if (!array)
		return (-1);
	va_start(args, format_str);
	ft_assign_content(array, arr_size, args);
	va_end(args);
	ft_process_tags(array, arr_size);
	ft_display(array, arr_size);
	printed_char = ft_count_char(array, arr_size);
	ft_free_array(array, arr_size);
	return (printed_char);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 16:40:45 by marnaudy          #+#    #+#             */
/*   Updated: 2021/12/03 09:34:34 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/libft.h"
#include "printf_utils.h"
#include "process_utils.h"

static void	ft_process_pointer(t_tag *tag)
{
	char			*output;

	output = ft_utoa_base((unsigned long int)tag->data, "0123456789abcdef");
	free(tag->text);
	tag->text = output;
	ft_add_precision(tag);
	output = ft_strjoin("0x", tag->text);
	free(tag->text);
	tag->text = output;
	ft_add_padding(tag);
}

static void	ft_process_percentage(t_tag *tag)
{
	free(tag->text);
	tag->text = malloc(sizeof(char) * 2);
	if (!tag->text)
		return ;
	tag->text[0] = '%';
	tag->text[1] = 0;
	ft_add_padding(tag);
}

void	ft_process_tags(t_tag *array, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (array[i].is_tag && array[i].specifier == 'c')
			ft_process_c(array + i);
		if (array[i].is_tag && array[i].specifier == 's')
			ft_process_str(array + i);
		if (array[i].is_tag && (array[i].specifier == 'i'
				|| array[i].specifier == 'd'))
			ft_process_int(array + i);
		if (array[i].is_tag && array[i].specifier == 'u')
			ft_process_unsigned_int(array + i);
		if (array[i].is_tag && (array[i].specifier == 'x'
				|| array[i].specifier == 'X'))
			ft_process_hex(array + i);
		if (array[i].is_tag && array[i].specifier == 'p')
			ft_process_pointer(array + i);
		if (array[i].is_tag && array[i].specifier == '%')
			ft_process_percentage(array + i);
		i++;
	}
}

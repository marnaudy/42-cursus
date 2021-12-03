/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 07:18:19 by marnaudy          #+#    #+#             */
/*   Updated: 2021/12/03 08:26:40 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include "libft/libft.h"
#include "printf_utils.h"

void	ft_free_array(t_tag *array, int size)
{
	int	i;

	i = 0;
	while (array && i < size)
	{
		free(array[i].text);
		i++;
	}
	free(array);
}

void	ft_display(t_tag *array, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (array[i].is_tag && array[i].specifier == 'c')
			write(1, array[i].text, array[i].width);
		else
			write(1, array[i].text, ft_strlen(array[i].text));
		i++;
	}
}

int	ft_count_char(t_tag *array, int size)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < size)
	{
		if (array[i].is_tag && array[i].specifier == 'c')
			count += array[i].width;
		else
			count += ft_strlen(array[i].text);
		i++;
	}
	return (count);
}

void	ft_assign_content(t_tag *array, int size, va_list args)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (array[i].is_tag && array[i].specifier != '%')
		{
			array[i].data = va_arg(args, void *);
		}
		i++;
	}
}

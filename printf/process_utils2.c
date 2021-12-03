/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 10:55:12 by marnaudy          #+#    #+#             */
/*   Updated: 2021/12/03 08:32:57 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/libft.h"
#include "printf_utils.h"
#include "process_utils.h"

void	ft_process_c(t_tag *tag)
{
	int	i;

	free(tag->text);
	if (!tag->width)
		tag->width = 1;
	tag->text = malloc(sizeof(char) * tag->width);
	if (!tag->text)
		return ;
	i = 0;
	if (tag->align_left)
	{
		tag->text[i] = (char)tag->data;
		i++;
	}
	else
		tag->text[tag->width - 1] = (char)tag->data;
	while (i < tag->width - 1 + tag->align_left)
	{
		tag->text[i] = tag->padding;
		i++;
	}
}

void	ft_process_str(t_tag *tag)
{
	char	*output;
	int		size;

	if (!tag->data)
		tag->data = "(null)";
	size = ft_strlen((char *)tag->data);
	if ((tag->precision >= 0) && (tag->precision < size))
		size = tag->precision;
	output = malloc(sizeof(char) * (size + 1));
	if (!output)
		return ;
	ft_strlcpy(output, (char *)tag->data, size + 1);
	free(tag->text);
	tag->text = output;
	ft_add_padding(tag);
}

void	ft_process_int(t_tag *tag)
{
	unsigned int	nb;

	nb = (int)tag->data;
	if ((int)tag->data < 0)
	{
		tag->sign = '-';
		nb = -1 * (int)tag->data;
	}
	free(tag->text);
	tag->text = ft_utoa_base(nb, "0123456789");
	ft_add_precision(tag);
	if (tag->padding == '0' && tag->sign)
	{
		tag->width--;
		ft_add_padding(tag);
		ft_add_sign(tag);
	}
	else
	{
		ft_add_sign(tag);
		ft_add_padding(tag);
	}
}

void	ft_process_unsigned_int(t_tag *tag)
{
	free(tag->text);
	tag->text = ft_utoa_base((unsigned int)tag->data, "0123456789");
	ft_add_precision(tag);
	ft_add_padding(tag);
}

void	ft_process_hex(t_tag *tag)
{
	char			*output;

	free(tag->text);
	if (tag->specifier == 'x')
		output = ft_utoa_base((unsigned int)tag->data, "0123456789abcdef");
	else
		output = ft_utoa_base((unsigned int)tag->data, "0123456789ABCDEF");
	tag->text = output;
	ft_add_precision(tag);
	if (tag->prefix && output && output[0])
	{
		if (tag->specifier == 'x')
			output = ft_strjoin("0x", tag->text);
		else
			output = ft_strjoin("0X", tag->text);
		free(tag->text);
		tag->text = output;
	}
	ft_add_padding(tag);
}

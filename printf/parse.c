/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 07:34:02 by marnaudy          #+#    #+#             */
/*   Updated: 2021/12/03 06:09:11 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "printf_utils.h"
#include "parse_utils.h"

static int	ft_is_valid_tag(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '%')
	{
		while (ft_is_in_set(str[i], "-0# +"))
			i++;
		while (ft_is_in_set(str[i], "0123456789"))
			i++;
		if (str[i] == '.')
			i++;
		while (ft_is_in_set(str[i], "0123456789"))
			i++;
		if (ft_is_in_set(str[i], "cspdiuxX%"))
			return (1);
	}
	return (0);
}

static void	ft_set_default_tags(t_tag *tag)
{
	tag->width = 0;
	tag->precision = -1;
	tag->align_left = 0;
	tag->prefix = 0;
	tag->padding = ' ';
	tag->sign = 0;
}

static void	ft_decode_flags(t_tag *tag)
{
	int	i;

	i = 1;
	while (tag->text[i])
	{
		if (tag->text[i] == '-')
		{
			tag->align_left = 1;
			tag->padding = ' ';
		}
		if (tag->text[i] == '0' && !tag->align_left)
			tag->padding = '0';
		if (tag->text[i] == '#')
			tag->prefix = 1;
		if (tag->text[i] == ' ' && !tag->sign)
			tag->sign = ' ';
		if (tag->text[i] == '+')
			tag->sign = '+';
		if (ft_is_in_set(tag->text[i], "123456789.cspdiuxX%"))
			return ;
		i++;
	}
}

static void	ft_decode_tags(t_tag *tag)
{
	int	i;

	i = 0;
	ft_set_default_tags(tag);
	ft_decode_flags(tag);
	tag->specifier = tag->text[ft_strlen(tag->text) - 1];
	while (tag->text[i])
	{
		if (ft_is_in_set(tag->text[i], "123456789"))
		{
			tag->width = ft_atoi(tag->text + i);
			while (ft_is_in_set(tag->text[i], "0123456789"))
				i++;
		}
		if (tag->text[i] == '.')
		{
			tag->precision = ft_atoi(tag->text + ++i);
			tag->padding = ' ';
			return ;
		}
		i++;
	}
}

int	ft_parse_format(const char *str, t_tag **array)
{
	int	i;
	int	size;

	size = ft_split_tags(str, array);
	if (!array)
		return (0);
	i = 0;
	while (i < size)
	{
		if (ft_is_valid_tag((*array)[i].text))
		{
			(*array)[i].is_tag = 1;
			ft_decode_tags((*array) + i);
		}
		else
			(*array)[i].is_tag = 0;
		i++;
	}
	return (size);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 08:54:21 by marnaudy          #+#    #+#             */
/*   Updated: 2021/11/30 18:23:57 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "printf_utils.h"
#include "libft/libft.h"

static int	ft_tag_length(const char	*str, int start)
{
	int	i;

	i = 0;
	if (str[start] == '%')
	{
		i++;
		while (ft_is_in_set(str[start + i], "-0# +"))
			i++;
		while (ft_is_in_set(str[start + i], "0123456789"))
			i++;
		if (ft_is_in_set(str[start + i], "."))
			i++;
		while (ft_is_in_set(str[start + i], "0123456789"))
			i++;
		if (ft_is_in_set(str[start + i], "cspdiuxX%"))
			return (i + 1);
	}
	while (str[start + i] && str[start + i] != '%')
		i++;
	return (i);
}

static int	ft_nb_tag(const char *str)
{
	int	i;
	int	tag_len;
	int	tag_count;

	i = 0;
	tag_count = 0;
	while (str[i])
	{
		tag_len = ft_tag_length(str, i);
		i += tag_len;
		tag_count++;
	}
	return (tag_count);
}

static t_tag	*ft_check_array(t_tag *array, int size)
{
	int	i;
	int	is_good;

	i = 0;
	is_good = !!array;
	while (i < size)
	{
		is_good = (is_good && array[i].text);
		i++;
	}
	if (is_good)
		return (array);
	i = 0;
	while (i < size)
	{
		free(array[i].text);
		i++;
	}
	free(array);
	return (NULL);
}

int	ft_split_tags(const char *str, t_tag **array)
{
	int		i;
	int		tag_len;
	int		nb_tag;
	int		arr_idx;

	nb_tag = ft_nb_tag(str);
	*array = malloc(sizeof(t_tag) * nb_tag);
	if (!*array)
		return (0);
	i = 0;
	arr_idx = 0;
	while (str[i])
	{
		tag_len = ft_tag_length(str, i);
		(*array)[arr_idx].text = ft_substr(str, i, tag_len);
		i += tag_len;
		arr_idx++;
	}
	*array = ft_check_array(*array, nb_tag);
	return (nb_tag);
}

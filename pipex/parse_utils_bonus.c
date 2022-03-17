/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 23:27:38 by marnaudy          #+#    #+#             */
/*   Updated: 2022/03/15 17:06:27 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static int	ft_substr_len(char const *s, int start, int len)
{
	int	max_len;

	max_len = ft_strlen(s) - start;
	if (max_len < 0)
		max_len = 0;
	if (max_len < (int) len)
		return (max_len);
	return (len);
}

static char	*ft_substr(char const *s, int start, int len)
{
	int		i;
	char	*new;

	new = malloc(sizeof(char) * (ft_substr_len(s, start, len) + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (s[i] && i < start)
		i++;
	if (!s[i])
	{
		new[0] = 0;
		return (new);
	}
	i = 0;
	while (s[start + i] && i < len)
	{
		new[i] = s[start + i];
		i++;
	}
	new[i] = 0;
	return (new);
}

static int	ft_nb_string(char const *s, char c)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			nb++;
			while (s[i] && s[i] != c)
				i++;
			i--;
		}
		i++;
	}
	return (nb);
}

static char	**ft_check_array(char **array, int size)
{
	int	i;
	int	is_good;

	i = 0;
	is_good = 1;
	while (i < size)
	{
		is_good = (is_good && array[i]);
		i++;
	}
	if (is_good)
		return (array);
	i = 0;
	while (i < size)
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		arr_idx;
	char	**array;

	array = malloc(sizeof(char *) * (ft_nb_string(s, c) + 1));
	if (!array)
		return (NULL);
	i = 0;
	arr_idx = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			j = 0;
			while (s[i + j] != c && s[i + j])
				j++;
			array[arr_idx++] = ft_substr(s, i, j);
			i += j - 1;
		}
		i++;
	}
	array[arr_idx] = NULL;
	return (ft_check_array(array, ft_nb_string(s, c)));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 22:52:01 by marnaudy          #+#    #+#             */
/*   Updated: 2021/11/29 13:15:13 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	i;
	unsigned int	start;
	unsigned int	size;

	start = 0;
	size = 0;
	i = 0;
	while (ft_is_in_set(s1[start], set) && s1[start])
		start++;
	while (s1[start + i])
	{
		if (!ft_is_in_set(s1[start + i], set))
			size = i + 1;
		i++;
	}
	return (ft_substr(s1, start, size));
}

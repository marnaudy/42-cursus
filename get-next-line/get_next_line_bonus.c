/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 07:07:22 by marnaudy          #+#    #+#             */
/*   Updated: 2021/11/26 12:43:38 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

t_buffer	*ft_get_buffer(t_buffer *array, int fd)
{
	int	i;

	i = 0;
	while (i < MAX_FILES)
	{
		if (array[i].fd == fd || !array[i].is_used)
			return (array + i);
		i++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	char			*str;
	static t_buffer	array[MAX_FILES];
	t_buffer		*buffer;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	str = 0;
	buffer = ft_get_buffer(array, fd);
	if (!buffer)
		return (0);
	while (1)
	{
		if (buffer->size == buffer->idx)
		{
			ft_read_file(fd, buffer);
			if (buffer->size <= 0)
				return (str);
		}
		str = ft_read_buffer(buffer, str);
		if (str && str[0] && str[ft_strlen(str) - 1] == '\n')
			return (str);
	}
}

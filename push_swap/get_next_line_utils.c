/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 12:24:13 by marnaudy          #+#    #+#             */
/*   Updated: 2021/11/26 11:32:38 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_line_size(t_buffer buffer)
{
	int		i;

	i = 0;
	while (buffer.idx + i < buffer.size)
	{
		if (buffer.content[buffer.idx + i] == '\n')
			return (i + 1);
		i++;
	}
	return (i);
}

char	*ft_strcat_buffer(char *str, t_buffer *buffer, int n)
{
	char	*new;
	int		i;
	int		j;

	new = malloc(sizeof(char) * (ft_strlen(str) + n + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (str && str[i])
	{
		new[i] = str[i];
		i++;
	}
	free(str);
	j = 0;
	while (j < n)
	{
		new[i + j] = buffer->content[buffer->idx];
		j++;
		buffer->idx++;
	}
	new[i + j] = 0;
	return (new);
}

void	ft_read_file(int fd, t_buffer *buffer)
{
	int	n;

	n = read(fd, buffer->content, BUFFER_SIZE);
	buffer->idx = 0;
	if (n < 0)
		n = 0;
	buffer->size = n;
}

char	*ft_read_buffer(t_buffer *buffer, char *str)
{
	int	line_len;

	if (buffer->idx < buffer->size)
	{
		line_len = ft_line_size(*buffer);
		str = ft_strcat_buffer(str, buffer, line_len);
	}
	return (str);
}

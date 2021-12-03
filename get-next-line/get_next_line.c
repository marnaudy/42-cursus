/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 07:07:22 by marnaudy          #+#    #+#             */
/*   Updated: 2021/11/26 11:33:48 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char			*str;
	static t_buffer	buffer;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	str = 0;
	while (1)
	{
		if (buffer.size == buffer.idx)
		{
			ft_read_file(fd, &buffer);
			if (buffer.size <= 0)
				return (str);
		}
		str = ft_read_buffer(&buffer, str);
		if (str && str[0] && str[ft_strlen(str) - 1] == '\n')
			return (str);
	}
}

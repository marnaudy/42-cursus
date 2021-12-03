/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 13:37:17 by marnaudy          #+#    #+#             */
/*   Updated: 2021/11/26 12:48:05 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

typedef struct s_buffer
{
	char	content[BUFFER_SIZE];
	int		idx;
	int		size;
}	t_buffer;

int		ft_strlen(char *s);
void	ft_read_file(int fd, t_buffer *buffer);
char	*ft_read_buffer(t_buffer *buffer, char *str);
char	*get_next_line(int fd);

#endif

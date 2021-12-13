/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 15:13:49 by marnaudy          #+#    #+#             */
/*   Updated: 2021/12/12 20:22:01 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "types.h"

int	fill_buffer(t_buffer_list *buffer)
{
	int	nb_read;

	if (buffer == NULL)
		return (0);
	nb_read = read(STDIN_FILENO, buffer->data + buffer->len,
			buffer->size - buffer->len);
	buffer->len += nb_read;
	if (nb_read == 0 && buffer->len && buffer->data[buffer->len - 1] != '\n')
	{
		buffer->data[buffer->len] = '\n';
		buffer->len++;
		nb_read++;
	}
	return (nb_read);
}

void	move_remaining(t_buffer_list *old, t_buffer_list *new)
{
	while (old->index < old->size)
	{
		new->data[new->len] = old->data[old->index];
		new->len++;
		old->index++;
	}
}

t_buffer_list	*new_buffer(t_buffer_list *current, int is_big_boi)
{
	t_buffer_list	*new;
	int				new_size;

	if (current->len < current->size)
		return (current);
	new_size = current->size * (1 + 10 * is_big_boi);
	new = malloc(sizeof(t_buffer_list) + new_size * sizeof(char));
	if (!new)
		return (NULL);
	new->next = NULL;
	new->size = new_size;
	new->len = 0;
	new->index = 0;
	move_remaining(current, new);
	current->next = new;
	return (new);
}

int	get_key(t_buffer_list *buffer, char **key)
{
	int	i;

	i = buffer->index;
	while (i != buffer->len && buffer->data[i] != '\n')
		i++;
	if (i == buffer->len)
		return (1);
	*key = buffer->data + buffer->index;
	buffer->index = i + 1;
	return (0);
}

int	get_entry(t_buffer_list *buffer, char **key, char **value)
{
	int		i;
	char	*begin_value;

	if (buffer->index != buffer->len
		&& buffer->data[buffer->index] == '\n')
	{
		buffer->index++;
		return (-1);
	}
	i = buffer->index;
	while (i != buffer->len && buffer->data[i] != '\n')
		i++;
	*key = buffer->data + buffer->index;
	if (i != buffer->len)
		i++;
	begin_value = buffer->data + i;
	while (i != buffer->len && buffer->data[i] != '\n')
		i++;
	if (i == buffer->len)
		return (1);
	*value = begin_value;
	buffer->index = i + 1;
	return (0);
}

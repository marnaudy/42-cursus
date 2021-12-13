/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 11:48:24 by cdittric          #+#    #+#             */
/*   Updated: 2021/12/12 15:54:27 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "proto.h"

int	putstr_ret(int fd, const char *str, int ret)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	write(fd, str, len);
	return (ret);
}

static int	free_and_ret(
				t_database *database,
				t_buffer_list *buffer_list,
				int ret)
{
	t_buffer_list	*to_free;

	database_free(database);
	while (buffer_list)
	{
		to_free = buffer_list;
		buffer_list = buffer_list->next;
		free(to_free);
	}
	return (ret);
}

t_buffer_list	*buffer_list_init(t_buffer_list **first)
{
	t_buffer_list	*new;

	new = malloc(sizeof(t_buffer_list) + sizeof(char) * CHUNK_SIZE);
	if (!new)
		return (NULL);
	new->size = CHUNK_SIZE;
	new->len = 0;
	new->index = 0;
	new->next = NULL;
	*first = new;
	return (new);
}

int	main(void)
{
	t_buffer_list	*first_buffer;
	t_buffer_list	*current_buffer;
	t_database		*database;

	current_buffer = buffer_list_init(&first_buffer);
	database = database_init();
	if (database == NULL || !current_buffer)
		return (free_and_ret(database, first_buffer,
				putstr_ret(2, "Failed to init database\n", -1)));
	current_buffer = read_entries(current_buffer, database);
	if (!current_buffer)
		return (free_and_ret(database, first_buffer,
				putstr_ret(2, "Error while reading entry\n", -1)));
	current_buffer = read_keys(current_buffer, database);
	bufwrite(0, 0, NULL);
	free_and_ret(database, first_buffer, 0);
	return (0);
}

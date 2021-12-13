/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 15:55:30 by marnaudy          #+#    #+#             */
/*   Updated: 2021/12/12 20:18:13 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <unistd.h>
#include "types.h"
#include "proto.h"

ssize_t	bufwrite(int print_nl, ssize_t ret, const char *str)
{
	static char		buf[WRITE_BUFFER_SIZE];
	static size_t	len;

	if (str == NULL)
	{
		ret += write(1, buf, len);
		len = 0;
		return (ret);
	}
	while (print_nl || *str != '\n')
	{
		if (*str == '\n')
		{
			buf[len++] = *str;
			print_nl = 0;
		}
		else
			buf[len++] = *str++;
		if (len == WRITE_BUFFER_SIZE)
		{
			ret += write(1, buf, len);
			len = 0;
		}
	}
	return (ret);
}

t_buffer_list	*read_entries(t_buffer_list *current, t_database *dbase)
{
	char	*key;
	char	*value;
	int		entry;
	int		first_loop;

	while (current)
	{
		if (fill_buffer(current) == 0)
			return (NULL);
		entry = get_entry(current, &key, &value);
		first_loop = 1;
		while (!entry)
		{
			first_loop = 0;
			if (database_add(dbase, key, value))
				return (NULL);
			entry = get_entry(current, &key, &value);
		}
		if (entry == -1)
			return (current);
		current = new_buffer(current, first_loop);
	}
	return (NULL);
}

t_buffer_list	*read_keys(t_buffer_list *current, t_database *dbase)
{
	char		*key;
	const char	*str;
	int			entry;
	int			first_loop;

	while (1)
	{
		entry = get_key(current, &key);
		first_loop = 1;
		while (!entry)
		{
			first_loop = 0;
			str = database_fetch(dbase, key);
			if (str)
				bufwrite(1, 0, str);
			else
				bufwrite(1, bufwrite(0, 0, key), ": Not found.\n");
			entry = get_key(current, &key);
		}
		current = new_buffer(current, first_loop);
		if (fill_buffer(current) == 0)
			return (NULL);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   database.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 10:57:16 by marnaudy          #+#    #+#             */
/*   Updated: 2021/12/12 11:32:16 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "types.h"

t_database	*database_init(void)
{
	t_database	*new;
	int			i;

	new = malloc(sizeof(t_database));
	if (!new)
		return (NULL);
	new->next = NULL;
	i = 0;
	while (i < DATABASE_SIZE)
	{
		new->data[i].key = NULL;
		i++;
	}
	return (new);
}

static unsigned int	hash_function(const char *key)
{
	int				i;
	unsigned int	hash;

	i = 0;
	hash = 0;
	while (key[i] != '\n' && key[i])
	{
		hash += key[i++];
		hash += hash << 10;
		hash ^= hash >> 6;
	}
	hash += hash << 3;
	hash ^= hash >> 11;
	hash += hash << 15;
	hash %= DATABASE_SIZE;
	return (hash);
}

static int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\n')
		i++;
	return (s1[i] - s2[i]);
}

int	database_add(t_database *dbase, const char *key, const char *value)
{
	int	hash;

	hash = hash_function(key);
	while (dbase->data[hash].key && ft_strcmp(dbase->data[hash].key, key))
	{
		if (!dbase->next)
			dbase->next = database_init();
		dbase = dbase->next;
		if (!dbase)
			return (1);
	}
	dbase->data[hash].key = key;
	dbase->data[hash].value = value;
	return (0);
}

const char	*database_fetch(t_database *database, const char *key)
{
	int	hash;

	hash = hash_function(key);
	while (database->data[hash].key && ft_strcmp(database->data[hash].key, key))
	{
		database = database->next;
		if (!database)
			return (NULL);
	}
	if (!database->data[hash].key)
		return (NULL);
	return (database->data[hash].value);
}

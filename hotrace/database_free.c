/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   database_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 12:22:27 by marnaudy          #+#    #+#             */
/*   Updated: 2021/12/11 18:38:59 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "types.h"

void	database_free(t_database *database)
{
	t_database	*to_free;

	while (database)
	{
		to_free = database;
		database = database->next;
		free(to_free);
	}
}

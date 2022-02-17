/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 10:13:44 by marnaudy          #+#    #+#             */
/*   Updated: 2022/02/12 13:08:14 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"

void	free_game(t_alcu *game)
{
	if (!game)
		return ;
	free(game->heaps);
	free(game);
}

void	free_text_list(t_text_list *list)
{
	t_text_list	*to_free;

	while (list)
	{
		to_free = list;
		list = list->next;
		free(to_free->text);
		free(to_free);
	}
}

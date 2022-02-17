/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 11:38:07 by marnaudy          #+#    #+#             */
/*   Updated: 2022/02/12 15:33:10 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"

int	main(int argc, char **argv)
{
	t_alcu	*game;

	game = parse(argc, argv);
	if (!game)
	{
		ft_putstr_fd("ERROR\n", STDERR_FILENO);
		return (1);
	}
	if (play_game(game))
	{
		ft_putstr_fd("ERROR\n", STDERR_FILENO);
		free_game(game);
		return (1);
	}
	free_game(game);
	return (0);
}

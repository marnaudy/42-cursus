/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 12:30:54 by marnaudy          #+#    #+#             */
/*   Updated: 2022/02/13 08:47:52 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"

static int	player_turn(t_alcu *game, int fd)
{
	char	*input;
	int		nb;

	nb = 0;
	while (1)
	{
		ft_putstr_fd("Please choose between 1 and 3 items\n", STDOUT_FILENO);
		input = get_next_line(fd);
		if (!input)
			return (1);
		nb = ft_atoi(input);
		if (nb < 1 || nb > 3 || nb > game->heaps[game->nb_heaps - 1].nb)
		{
			write(STDERR_FILENO, input, ft_strlen(input) - (input[0] != 0));
			ft_putstr_fd(" - Invalid choice\n", STDERR_FILENO);
			free(input);
			continue ;
		}
		free(input);
		break ;
	}
	game->heaps[game->nb_heaps - 1].nb -= nb;
	if (game->heaps[game->nb_heaps - 1].nb == 0)
		game->nb_heaps--;
	return (0);
}

static void	init_ai(t_alcu *game)
{
	int	i;

	game->heaps[0].want_to_end = 0;
	i = 1;
	while (i < game->nb_heaps)
	{
		if (game->heaps[i - 1].want_to_end)
			game->heaps[i].want_to_end = (game->heaps[i - 1].nb % 4 == 0);
		else
			game->heaps[i].want_to_end = (game->heaps[i - 1].nb % 4 == 1);
		i++;
	}
}

static void	computer_turn(t_alcu *game)
{
	int	nb;

	if (game->heaps[game->nb_heaps - 1].want_to_end)
		nb = game->heaps[game->nb_heaps - 1].nb % 4;
	else
		nb = (game->heaps[game->nb_heaps - 1].nb + 3) % 4;
	if (nb == 0)
		nb = 1;
	game->heaps[game->nb_heaps - 1].nb -= nb;
	if (game->heaps[game->nb_heaps - 1].nb == 0)
		game->nb_heaps--;
	ft_putstr_fd("AI took ", STDOUT_FILENO);
	ft_putnbr_fd(nb, STDOUT_FILENO);
	ft_putstr_fd("\n", STDOUT_FILENO);
}

int	play_game(t_alcu *game)
{
	int	fd;

	fd = open("/dev/tty", O_RDONLY);
	if (fd < 0)
		return (1);
	init_ai(game);
	while (game->heaps[0].nb)
	{
		display(game);
		computer_turn(game);
		if (game->heaps[0].nb == 0)
			ft_putstr_fd("You are the winner! Congratulations!\n",
				STDOUT_FILENO);
		if (game->heaps[0].nb == 0)
			break ;
		if (display(game) || player_turn(game, fd))
		{
			close (fd);
			return (1);
		}
		if (game->heaps[0].nb == 0)
			ft_putstr_fd("You lose :(\n", STDOUT_FILENO);
	}
	close (fd);
	return (0);
}

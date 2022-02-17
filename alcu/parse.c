/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 09:44:09 by marnaudy          #+#    #+#             */
/*   Updated: 2022/02/13 07:47:37 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"

static t_text_list	*read_line(int fd)
{
	t_text_list	*line;
	char		*text;

	text = get_next_line(fd);
	if (!text)
		return (NULL);
	line = malloc(sizeof(t_text_list));
	if (!line || (!fd && text[0] == '\n'))
	{
		free(text);
		free(line);
		return (NULL);
	}
	line->next = NULL;
	line->text = text;
	return (line);
}

static t_text_list	*read_file(t_alcu *game, char *filename)
{
	int			fd;
	t_text_list	*start;
	t_text_list	*last;

	if (filename)
		fd = open(filename, O_RDONLY);
	else
		fd = STDIN_FILENO;
	game->nb_heaps = 0;
	if (fd < 0)
		return (NULL);
	start = read_line(fd);
	last = start;
	while (last)
	{
		last->next = read_line(fd);
		last = last->next;
		game->nb_heaps++;
	}
	if (filename)
		close(fd);
	return (start);
}

static t_alcu	*init_game(void)
{
	t_alcu	*game;

	game = malloc(sizeof(t_alcu));
	if (!game)
		return (NULL);
	game->heaps = NULL;
	game->nb_heaps = 0;
	return (game);
}

static int	parse_text(t_alcu *game, t_text_list *list)
{
	int	i;
	int	nb;

	if (!list)
		return (1);
	game->heaps = malloc(sizeof(t_heap) * game->nb_heaps);
	if (!game->heaps)
		return (1);
	i = 0;
	while (i < game->nb_heaps && list)
	{
		nb = ft_atoi(list->text);
		if (nb < 1 || nb > 10000)
			return (1);
		game->heaps[i].nb = nb;
		list = list->next;
		i++;
	}
	return (0);
}

t_alcu	*parse(int argc, char **argv)
{
	char		*filename;
	t_text_list	*text_list;
	t_alcu		*game;

	if (argc > 2)
		return (NULL);
	filename = NULL;
	if (argc == 2)
		filename = argv[1];
	game = init_game();
	if (!game)
		return (NULL);
	text_list = read_file(game, filename);
	if (parse_text(game, text_list))
	{
		free_game(game);
		free_text_list(text_list);
		return (NULL);
	}
	free_text_list(text_list);
	return (game);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:26:30 by marnaudy          #+#    #+#             */
/*   Updated: 2022/02/16 14:46:02 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"

static t_text_list	*read_line(int fd)
{
	t_text_list	*line;
	char		*text;

	text = get_next_line(fd);
	if (!text)
		return (NULL);
	line = malloc(sizeof(t_text_list));
	if (!line)
	{
		free(text);
		return (NULL);
	}
	line->next = NULL;
	line->text = text;
	return (line);
}

static t_text_list	*read_file(t_fdf *data, char *filename)
{
	int			fd;
	int			nb_line;
	t_text_list	*start;
	t_text_list	*last;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	start = read_line(fd);
	last = start;
	nb_line = 0;
	while (last)
	{
		last->next = read_line(fd);
		last = last->next;
		nb_line++;
	}
	data->nb_lin = nb_line;
	if (close(fd))
	{
		free_text_list(start);
		return (NULL);
	}
	return (start);
}

static t_fdf	*init_data(char *name)
{
	t_fdf	*data;

	data = malloc(sizeof(t_fdf));
	if (!data)
		return (NULL);
	data->points = NULL;
	data->display = NULL;
	data->mlx = NULL;
	data->mlx_win = NULL;
	data->name = name;
	data->nb_lin = 0;
	data->nb_col = 0;
	return (data);
}

static int	alloc_display_coords(t_fdf *data)
{
	int	i;

	data->display = malloc(sizeof(t_2d_point *) * data->nb_lin);
	if (!data->display)
		return (1);
	ft_bzero(data->display, (size_t) data->nb_lin * sizeof(t_2d_point));
	i = 0;
	while (i < data->nb_lin)
	{
		data->display[i] = malloc(sizeof(t_2d_point) * data->nb_col);
		if (!data->display[i])
			return (1);
		i++;
	}
	return (0);
}

t_fdf	*parse(int argc, char **argv)
{
	t_fdf		*data;
	t_text_list	*text;

	if (argc != 2)
		return (NULL);
	data = init_data(argv[1]);
	if (!data || !valid_filename(argv[1]))
	{
		free(data);
		return (NULL);
	}
	text = read_file(data, argv[1]);
	if (parse_file(data, text) || alloc_display_coords(data))
	{
		free_all(data, text);
		return (NULL);
	}
	free_text_list(text);
	return (data);
}

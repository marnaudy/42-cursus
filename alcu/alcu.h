/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alcu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 09:43:27 by marnaudy          #+#    #+#             */
/*   Updated: 2022/02/13 08:47:35 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALCU_H
# define ALCU_H

# define BUFFER_SIZE 100

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_heap
{
	int	nb;
	int	want_to_end;
}	t_heap;

typedef struct s_buffer
{
	char	content[BUFFER_SIZE];
	int		idx;
	int		size;
}	t_buffer;

typedef struct s_text_list
{
	char				*text;
	struct s_text_list	*next;
}	t_text_list;

typedef struct s_alcu
{
	t_heap	*heaps;
	int		nb_heaps;
}	t_alcu;

size_t	ft_strlen(const char *s);
int		ft_atoi(const char *nptr);
char	*get_next_line(int fd);
void	free_game(t_alcu *data);
void	free_text_list(t_text_list *list);
t_alcu	*parse(int argc, char **argv);
void	ft_putstr_fd(char *s, int fd);
void	ft_n_putstr(char *str, int n);
int		display(t_alcu *data);
void	ft_putnbr_fd(int n, int fd);
int		play_game(t_alcu *game);

#endif

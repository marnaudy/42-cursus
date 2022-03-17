/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 21:09:46 by marnaudy          #+#    #+#             */
/*   Updated: 2022/03/17 10:53:21 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include <stdio.h>
# include <sys/wait.h>

# define BUFFER_SIZE 100

typedef struct s_buffer
{
	char	content[BUFFER_SIZE];
	int		idx;
	int		size;
}	t_buffer;

typedef struct s_command
{
	char	*path;
	char	**args;
}	t_command;

typedef struct s_pipex
{
	char		*name;
	t_command	*exec;
	int			nb_com;
	int			pid;
	char		**filenames;
	int			*pipe_fd;
	char		**envp;
	char		*limiter;
	char		*here_doc;
}	t_pipex;

int		ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, int n);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strcat_slash(char *s1, char *s2);
void	ft_putstr_fd(char *s1, char *s2, int fd);
char	*ft_strcat(char *s1, char *s2);
t_pipex	*init(int n, char *name);
void	close_pipex(t_pipex *data, int ret);
char	**ft_split(char const *s, char c);
t_pipex	*parse(int argc, char **argv);
void	open_pipes(t_pipex *data);
void	close_pipes(t_pipex *data, int n);
int		open_infile(t_pipex *data);
int		open_outfile(t_pipex *data);
void	search_path(t_pipex *data, int n, int path_line);
void	find_exec(t_pipex *data, int n);
char	*get_next_line(int fd, int *status);
void	read_heredoc(t_pipex *data);
void	write_heredoc(t_pipex *data);
void	exec_command(t_pipex *data, int n);
int		fork_pipex(t_pipex *data);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 21:09:50 by marnaudy          #+#    #+#             */
/*   Updated: 2022/03/17 10:57:27 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*data;
	int		status;

	data = parse(argc, argv);
	data->envp = envp;
	open_pipes(data);
	if (data->limiter)
	{
		read_heredoc(data);
		write_heredoc(data);
	}
	if (fork_pipex(data))
	{
		close_pipes(data, -1);
		while (wait(NULL) != -1)
			;
		close_pipex(data, 1);
	}
	close_pipes(data, -1);
	waitpid(data->pid, &status, 0);
	while (wait(NULL) != -1)
		;
	close_pipex(data, WEXITSTATUS(status));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 21:09:50 by marnaudy          #+#    #+#             */
/*   Updated: 2022/03/17 10:56:58 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*data;
	int		status;

	data = parse(argc, argv);
	data->envp = envp;
	open_pipe(data);
	if (fork_pipex(data))
	{
		close_pipe(data);
		while (wait(NULL) != -1)
			;
		close_pipex(data, 1);
	}
	close_pipe(data);
	waitpid(data->pid, &status, 0);
	while (wait(NULL) != -1)
		;
	close_pipex(data, WEXITSTATUS(status));
}

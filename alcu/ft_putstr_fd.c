/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:06:42 by marnaudy          #+#    #+#             */
/*   Updated: 2022/02/12 11:36:13 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(fd, s + i, 1);
		i++;
	}
}

void	ft_n_putstr(char *str, int n)
{
	while (n)
	{
		ft_putstr_fd(str, STDOUT_FILENO);
		--n;
	}
}

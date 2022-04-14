/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_semaphore_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 09:18:23 by marnaudy          #+#    #+#             */
/*   Updated: 2022/04/12 11:12:34 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	ft_strlen(char *s)
{
	int	size;

	if (!s)
		return (0);
	size = 0;
	while (s[size])
		size++;
	return (size);
}

static char	*ft_strcat(char *s1, char *s2)
{
	char			*new;
	unsigned int	i;
	unsigned int	j;

	new = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!new)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		new[i + j] = s2[j];
		j++;
	}
	new[i + j] = 0;
	return (new);
}

static char	*ft_utoa(unsigned int n)
{
	char			*new;
	unsigned int	i;
	unsigned int	size;

	i = n;
	size = 0;
	while (i)
	{
		i /= 10;
		size++;
	}
	new = malloc(sizeof(char) * (size + 1));
	if (!new)
		return (NULL);
	new[size] = 0;
	i = size - 1;
	while (n)
	{
		new[i] = n % 10 + '0';
		i--;
		n /= 10;
	}
	return (new);
}

char	*sem_name(unsigned int philo_nb, enum e_sem_type type)
{
	char	*name;
	char	*philo_tag;

	philo_tag = ft_utoa(philo_nb);
	if (!philo_tag)
		return (NULL);
	if (type == last_meal)
		name = ft_strcat("last_meal_", philo_tag);
	if (type == will)
		name = ft_strcat("will_", philo_tag);
	free(philo_tag);
	return (name);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 10:55:51 by marnaudy          #+#    #+#             */
/*   Updated: 2021/12/03 07:26:37 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/libft.h"
#include "printf_utils.h"

void	ft_add_sign(t_tag *tag)
{
	int		len;
	char	*new;

	if (!tag->text || !tag->sign)
		return ;
	len = ft_strlen(tag->text);
	new = malloc(sizeof(char) * (len + 2));
	if (!new)
		return ;
	new[0] = tag->sign;
	ft_strlcpy(new + 1, tag->text, len + 1);
	free(tag->text);
	tag->text = new;
}

void	ft_add_precision(t_tag *tag)
{
	int		len;
	int		nb_padding;
	char	*new;

	if (!tag->text)
		return ;
	if (tag->precision < 0)
		tag->precision = 1;
	len = ft_strlen(tag->text);
	nb_padding = tag->precision - len;
	if (nb_padding <= 0)
		return ;
	new = malloc(sizeof(char) * (len + nb_padding + 1));
	if (!new)
		return ;
	ft_strlcpy(new + nb_padding, tag->text, len + 1);
	ft_memset(new, '0', nb_padding);
	free(tag->text);
	tag->text = new;
}

void	ft_add_padding(t_tag *tag)
{
	int		start;
	int		len;
	int		nb_padding;
	char	*new;

	if (!tag->text)
		return ;
	len = ft_strlen(tag->text);
	nb_padding = tag->width - len;
	if (nb_padding <= 0)
		return ;
	new = malloc(sizeof(char) * (len + nb_padding + 1));
	if (!new)
		return ;
	start = (!tag->align_left * nb_padding);
	ft_strlcpy(new + start, tag->text, len + 1);
	start = (tag->align_left * len);
	ft_memset(new + start, tag->padding, nb_padding);
	new[len + nb_padding] = 0;
	free(tag->text);
	tag->text = new;
}

static unsigned int	ft_nb_size(unsigned long int n, int base_size)
{
	unsigned int	size;

	size = 0;
	while (n)
	{
		size++;
		n /= base_size;
	}
	return (size);
}

char	*ft_utoa_base(unsigned long int n, char *base)
{
	char			*new;
	unsigned int	i;
	unsigned int	size;
	unsigned int	base_size;

	base_size = ft_strlen(base);
	size = ft_nb_size(n, base_size);
	new = malloc(sizeof(char) * (size + 1));
	if (!new)
		return (NULL);
	new[size] = 0;
	i = size - 1;
	while (n)
	{
		new[i] = base[n % base_size];
		i--;
		n /= base_size;
	}
	return (new);
}

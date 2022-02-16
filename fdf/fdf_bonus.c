/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 12:02:52 by marnaudy          #+#    #+#             */
/*   Updated: 2022/02/16 09:34:44 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	main(int argc, char **argv)
{
	t_fdf	*data;

	data = parse(argc, argv);
	if (!data)
		return (1);
	if (data->nb_lin && data->nb_col)
		display(data);
	free_data(data);
	return (0);
}

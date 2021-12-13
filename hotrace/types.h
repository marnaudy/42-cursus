/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 11:48:46 by cdittric          #+#    #+#             */
/*   Updated: 2021/12/12 15:07:45 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include <stddef.h>

# define DATABASE_SIZE 500009
# define CHUNK_SIZE 40000
# define WRITE_BUFFER_SIZE 40000

typedef struct s_data
{
	const char	*key;
	const char	*value;
}	t_data;

typedef struct s_database
{
	t_data				data[DATABASE_SIZE];
	struct s_database	*next;
}	t_database;

typedef struct s_buffer_list
{
	int						index;
	int						size;
	int						len;
	struct s_buffer_list	*next;
	char					data[];
}	t_buffer_list;

#endif

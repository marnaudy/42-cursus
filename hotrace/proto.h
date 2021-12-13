/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 11:48:09 by cdittric          #+#    #+#             */
/*   Updated: 2021/12/12 12:38:39 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTO_H
# define PROTO_H
# include "types.h"

t_database		*database_init(void);
int				database_add(t_database *dbase,
					const char *key, const char *value);
const char		*database_fetch(t_database *database, const char *key);
void			database_free(t_database *database);
int				fill_buffer(t_buffer_list *buffer);
void			move_remaining(t_buffer_list *old, t_buffer_list *new);
t_buffer_list	*new_buffer(t_buffer_list *current, int is_big_boi);
int				get_key(t_buffer_list *buffer, char **key);
int				get_entry(t_buffer_list *buffer, char **key, char **value);
t_buffer_list	*read_entries(t_buffer_list *current, t_database *dbase);
t_buffer_list	*read_keys(t_buffer_list *current, t_database *dbase);
int				putstr_ret(int fd, const char *str, int ret);
ssize_t			bufwrite(int print_nl, ssize_t ret, const char *str);

#endif

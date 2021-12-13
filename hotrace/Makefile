# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/11 11:51:12 by marnaudy          #+#    #+#              #
#    Updated: 2021/12/12 13:02:12 by marnaudy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	hotrace

SRCS	=	parse_utils.c \
			parse.c \
			database.c \
			database_free.c \
			main.c

HEADERS	=	types.h \
			proto.h

OBJS	=	${SRCS:.c=.o}

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror

RM		=	rm -f

all:		${NAME}

${NAME}:	${OBJS}
			${CC} -o ${NAME} ${OBJS}

.c.o:		${HEADERS}
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re

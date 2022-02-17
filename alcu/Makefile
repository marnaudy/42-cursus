# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/02 14:17:42 by marnaudy          #+#    #+#              #
#    Updated: 2022/02/13 07:49:38 by marnaudy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	AlCu

SRCS	=	ft_strlen.c \
			ft_atoi.c \
			get_next_line.c \
			parse.c \
			free.c \
			display.c \
			ft_putstr_fd.c \
			main.c \
			play_game.c \
			ft_putnbr_fd.c

OBJS	=	${SRCS:.c=.o}

HEADER	=	alcu.h

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror

RM		=	rm -f

all:		${NAME}

${NAME}:	${OBJS}
			${CC} ${OBJS} -o ${NAME}

%.o:		%.c ${HEADER}
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all bonus clean fclean re

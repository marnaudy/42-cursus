# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/02 14:17:42 by marnaudy          #+#    #+#              #
#    Updated: 2022/04/07 17:30:27 by marnaudy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo

SRCS	=	free.c \
			ft_atoi.c \
			parse.c \
			mutex.c \
			time.c \
			display.c \
			philo_utils.c \
			philo.c \
			threads.c \
			monitor_philos.c \
			main.c

HEADERS	=	philo.h

OBJS	=	${SRCS:.c=.o}

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror

RM		=	rm -f

all:		${NAME}

${NAME}:	${OBJS}
			${CC} ${OBJS} -pthread -o ${NAME}

%.o:		%.c	${HEADERS}
			${CC} ${CFLAGS} -pthread -c $< -o ${<:.c=.o}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re

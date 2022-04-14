# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/02 14:17:42 by marnaudy          #+#    #+#              #
#    Updated: 2022/04/14 09:20:10 by marnaudy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo_bonus

SRCS	=	ft_atoi.c \
			parse.c \
			global_semaphores.c \
			philo_semaphore_utils.c \
			philo_semaphores.c \
			time.c \
			display.c \
			philo_utils.c \
			philo.c \
			philo_threads.c \
			main_threads.c \
			processes.c \
			main.c

HEADERS	=	philo.h

OBJS	=	${SRCS:.c=.o}

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror

RM		=	rm -f

all:		${NAME}

bonus:		${NAME}

${NAME}:	${OBJS}
			${CC} ${OBJS} -pthread -o ${NAME}

%.o:		%.c	${HEADERS}
			${CC} ${CFLAGS} -pthread -c $< -o ${<:.c=.o}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re bonus

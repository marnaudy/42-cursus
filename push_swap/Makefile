# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/13 15:22:45 by marnaudy          #+#    #+#              #
#    Updated: 2021/12/23 16:06:42 by marnaudy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

NAME_B	=	checker

SRCS	=	move_utils.c \
			move_utils2.c \
			move_utils3.c \
			move.c \
			parse.c \
			search.c \
			insert_utils.c \
			insert.c \
			push_swap_utils.c \
			sort_3.c \
			sort.c \
			push_swap.c

SRCS_B	=	move_utils.c \
			move_utils2.c \
			move_utils3.c \
			move.c \
			parse.c \
			push_swap_utils.c \
			get_next_line_utils.c \
			get_next_line.c \
			checker.c

HEADERS	=	move_utils.h \
			move.h \
			search.h \
			insert_utils.h \
			insert.h \
			sort_utils.h \
			push_swap_utils.h

OBJS	=	${SRCS:.c=.o}

OBJS_B	=	${SRCS_B:.c=.o}

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror

RM		=	rm -f

all:		${NAME}

${NAME}:	${OBJS}
			${CC} -o ${NAME} ${OBJS}

${NAME_B}:	${OBJS_B}
			${CC} -o ${NAME_B} ${OBJS_B}

bonus:		${NAME_B}

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

clean:
			${RM} ${OBJS} ${OBJS_B}

fclean:		clean
			${RM} ${NAME} ${NAME_B}

re:			fclean all

.PHONY:		all bonus clean fclean re

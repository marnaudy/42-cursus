# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/02 14:17:42 by marnaudy          #+#    #+#              #
#    Updated: 2022/03/16 21:17:32 by marnaudy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	pipex

NAME_B	=	pipex_bonus

SRCS	=	str_utils.c \
			str_utils2.c \
			init.c \
			parse_utils.c \
			parse.c \
			pipes.c \
			files.c \
			path_utils.c \
			path.c \
			exit.c \
			exec.c \
			fork.c \
			pipex.c

SRCS_B	=	str_utils_bonus.c \
			str_utils2_bonus.c \
			init_bonus.c \
			parse_utils_bonus.c \
			parse_bonus.c \
			pipes_bonus.c \
			files_bonus.c \
			path_utils_bonus.c \
			path_bonus.c \
			exit_bonus.c \
			gnl_bonus.c \
			heredoc_bonus.c \
			exec_bonus.c \
			fork_bonus.c \
			pipex_bonus.c

HEADERS	=	pipex.h \
			pipex_bonus.h

OBJS	=	${SRCS:.c=.o}

OBJS_B	=	${SRCS_B:.c=.o}

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

RM		=	rm -f

all:		${NAME}

${NAME}:	${OBJS}
			${CC} ${OBJS} -o ${NAME}

${NAME_B}:	${OBJS_B}
			${CC} ${OBJS_B} -o ${NAME_B}

bonus:		${NAME_B}

%.o:		%.c	${HEADERS}
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

clean:
			${RM} ${OBJS} ${OBJS_B}

fclean:		clean
			${RM} ${NAME} ${NAME_B}

re:			fclean all

.PHONY:		all bonus clean fclean re

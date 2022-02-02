# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/02 14:17:42 by marnaudy          #+#    #+#              #
#    Updated: 2022/02/02 14:34:55 by marnaudy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fdf

NAME_B	=	fdf_bonus

SRCS	=	main.c

SRCS_B	=	

HEADERS	=	

OBJS	=	${SRCS:.c=.o}

OBJS_B	=	${SRCS_B:.c=.o}

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

RM		=	rm -f

all:		${NAME}

${NAME}:	${OBJS}
			${CC} ${OBJS} -L ~/minilibx-linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o ${NAME}

${NAME_B}:	${OBJS_B}
			${CC} ${OBJS_B} -L ~/minilibx-linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o ${NAME_B}

bonus:		${NAME_B}

.c.o:
			${CC} ${CFLAGS} -I ~/minilibx-linux -c $< -o ${<:.c=.o}

clean:
			${RM} ${OBJS} ${OBJS_B}

fclean:		clean
			${RM} ${NAME} ${NAME_B}

re:			fclean all

.PHONY:		all bonus clean fclean re

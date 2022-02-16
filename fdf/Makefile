# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/02 14:17:42 by marnaudy          #+#    #+#              #
#    Updated: 2022/02/16 10:27:20 by marnaudy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fdf

NAME_B	=	fdf_bonus

LIBFT	=	libft/libft.a

SRCS	=	fdf.c \
			parse.c \
			parse_utils.c \
			draw_line.c \
			display_utils.c \
			display.c \
			free.c \
			isometrify.c

SRCS_B	=	fdf_bonus.c \
			parse_bonus.c \
			parse_utils_bonus.c \
			draw_line_bonus.c \
			draw_line_utils_bonus.c \
			display_utils_bonus.c \
			events_bonus.c \
			display_bonus.c \
			free_bonus.c \
			move_bonus.c

HEADERS	=	fdf.h \
			fdf_bonus.h

OBJS	=	${SRCS:.c=.o}

OBJS_B	=	${SRCS_B:.c=.o}

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

RM		=	rm -f

all:		${NAME}

${NAME}:	${OBJS} ${LIBFT}
			${CC} ${OBJS} -L libft -lft -L ~/minilibx-linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -o ${NAME}

${NAME_B}:	${OBJS_B} ${LIBFT}
			${CC} ${OBJS_B} -L libft -lft -L ~/minilibx-linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -o ${NAME_B}

${LIBFT}:
			make -C libft

bonus:		${NAME_B}

%.o:		%.c	${HEADERS}
			${CC} ${CFLAGS} -I ~/minilibx-linux -c $< -o ${<:.c=.o}

clean:
			${RM} ${OBJS} ${OBJS_B}
			make -C libft clean

fclean:		clean
			${RM} ${NAME} ${NAME_B} ${LIBFT}

re:			fclean all

.PHONY:		all bonus clean fclean re

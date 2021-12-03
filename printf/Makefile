NAME		= libftprintf.a

LIBDIR		= ./libft/

SRCS		= 	parse_utils.c \
				parse.c \
				process_utils.c \
				process_utils2.c \
				process.c \
				printf_utils.c \
				ft_printf.c


OBJS		=	${SRCS:.c=.o}

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror

RM			=	rm -f

AR			=	ar

AR_FLAGS 	=	rcs

all:		${NAME}

${NAME}:	${OBJS}
			make -C ${LIBDIR}
			cp ${LIBDIR}/libft.a ./${NAME}
			${AR} ${AR_FLAGS} ${NAME} ${OBJS}

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

clean:
			${RM} ${OBJS}
			make -C ${LIBDIR} clean

fclean:		clean
			${RM} ${NAME}
			make -C ${LIBDIR} fclean

re:			fclean all

.PHONY:		all clean fclean re bonus

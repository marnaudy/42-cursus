# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/04 17:15:05 by marnaudy          #+#    #+#              #
#    Updated: 2022/09/20 17:25:39 by marnaudy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		=	hi

SRCS		=	main.cpp

OBJS		=	${SRCS:.cpp=.o}

CXX			=	c++

CPPFLAGS	=	-Wall -Wextra -Werror -std=c++98

RM			=	rm -f

all:		${NAME}

${NAME}:	${OBJS}
			${CXX} ${OBJS} -o ${NAME}

%.o:		%.cpp ${HEADERS}
			${CXX} ${CPPFLAGS} -c $< -o ${<:.cpp=.o}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re

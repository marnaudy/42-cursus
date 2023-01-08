# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/04 17:15:05 by marnaudy          #+#    #+#              #
#    Updated: 2023/01/08 10:31:49 by marnaudy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		=	convert

SRCS		=	ScalarConverter.cpp \
				main.cpp

OBJS		=	${SRCS:.cpp=.o}

HEADERS 	=	ScalarConverter.hpp

CXX			=	c++

CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98

RM			=	rm -f

all:		${NAME}

${NAME}:	${OBJS}
			${CXX} ${OBJS} -o ${NAME}

%.o:		%.cpp ${HEADERS}
			${CXX} ${CXXFLAGS} -c $< -o ${<:.cpp=.o}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re

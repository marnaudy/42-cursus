# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/04 17:15:05 by marnaudy          #+#    #+#              #
#    Updated: 2022/09/21 07:18:57 by marnaudy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		=	complain

SRCS		=	Harl.cpp \
				main.cpp

OBJS		=	${SRCS:.cpp=.o}

HEADERS 	=	Harl.hpp

CXX			=	c++

CPPFLAGS	=	-Wall -Wextra -Werror -std=c++98 -g

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

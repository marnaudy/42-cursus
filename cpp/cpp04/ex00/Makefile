# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/04 17:15:05 by marnaudy          #+#    #+#              #
#    Updated: 2022/11/21 09:26:55 by marnaudy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		=	polymorphism

SRCS		=	Animal.cpp \
				Cat.cpp \
				Dog.cpp \
				WrongAnimal.cpp \
				WrongCat.cpp \
				main.cpp

OBJS		=	${SRCS:.cpp=.o}

HEADERS 	=	Animal.hpp \
				Cat.cpp \
				Dog.cpp \
				WrongAnimal.cpp \
				WrongCat.cpp

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

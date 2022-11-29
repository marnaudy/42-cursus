# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/04 17:15:05 by marnaudy          #+#    #+#              #
#    Updated: 2022/11/29 16:43:56 by marnaudy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		=	ex04

SRCS		=	AMateria.cpp \
				Cure.cpp \
				Ice.cpp \
				Character.cpp \
				MateriaSource.cpp \
				main.cpp

OBJS		=	${SRCS:.cpp=.o}

HEADERS 	=	AMateria.hpp \
				Cure.hpp \
				Ice.hpp \
				ICharacter.hpp \
				Character.hpp \
				IMateriaSource.hpp \
				MateriaSource.hpp

CXX			=	c++

CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98 -g

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

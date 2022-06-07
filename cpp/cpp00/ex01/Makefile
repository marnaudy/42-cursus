# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/04 17:15:05 by marnaudy          #+#    #+#              #
#    Updated: 2022/06/07 08:48:19 by marnaudy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	=	phonebook

SRCS	=	Contact.cpp \
			PhoneBook.cpp \
			main.cpp

OBJS	=	${SRCS:.cpp=.o}

HEADERS =	Contact.hpp \
			PhoneBook.hpp

CC		=	c++

CFLAGS	=	-Wall -Wextra -Werror -std=c++98

RM		=	rm -f

all:		${NAME}

${NAME}:	${OBJS}
			${CC} ${OBJS} -o ${NAME}

%.o:		%.cpp ${HEADERS}
			${CC} ${CFLAGS} -c $< -o ${<:.cpp=.o}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re

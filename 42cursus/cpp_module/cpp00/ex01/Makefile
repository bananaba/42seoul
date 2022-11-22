# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: balee <balee@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/22 16:28:11 by balee             #+#    #+#              #
#    Updated: 2022/11/22 16:54:26 by balee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= PhoneBook

CC			= c++
CFLAG		= -Wall -Werror -Wextra -std=c++98
RM			= rm -f

INCS		= -I.
SRCS		= main.cpp PhoneBook.cpp
OBJS		= $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAG) -o $(NAME) $(OBJS)

.cpp.o: $(SRC)
	$(CC) $(CFLAG) $(INCS) -c -o $@ $<

clean :
	$(RM) $(OBJS)

fclean :
	make clean
	$(RM) $(NAME)

re :
	make fclean
	make all

PHONY : all clean fclean re

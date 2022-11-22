# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: balee <balee@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/22 16:27:48 by balee             #+#    #+#              #
#    Updated: 2022/11/22 16:54:52 by balee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= megaphone

CC			= c++
CFLAG		= -Wall -Werror -Wextra -std=c++98
RM			= rm -f

SRCS		= megaphone.cpp
OBJS		= $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAG) -o $(NAME) $(OBJS)

.cpp.o: $(SRC)
	$(CC) $(CFLAG) -c -o $@ $<

clean :
	$(RM) $(OBJS)

fclean :
	make clean
	$(RM) $(NAME)

re :
	make fclean
	make all

test :
	./$(NAME) "shhhhh... I think the students are asleep..."
	./$(NAME) Damnit " ! " "Sorry students, I thought this thing was off."
	./$(NAME)

PHONY : all clean fclean re test

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: balee <balee@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/22 16:28:24 by balee             #+#    #+#              #
#    Updated: 2022/11/22 16:54:44 by balee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= Job

CC			= c++
CFLAG		= -Wall -Werror -Wextra -std=c++98
RM			= rm -f

INCS		= -I.
SRCS		= tests.cpp Account.cpp
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

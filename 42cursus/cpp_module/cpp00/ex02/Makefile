# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: balee <balee@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/22 16:28:24 by balee             #+#    #+#              #
#    Updated: 2022/11/22 19:23:41 by balee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= Job

CFLAGS		= -Wall -Werror -Wextra -std=c++98

INCS		= -I.
SRCS		= tests.cpp Account.cpp
OBJS		= $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CFLAGS) -o $(NAME) $(OBJS)

.cpp.o: $(SRC)
	$(CXX) $(CFLAGS) $(INCS) -c -o $@ $<

clean :
	$(RM) $(OBJS)

fclean :
	make clean
	$(RM) $(NAME)

re :
	make fclean
	make all

PHONY : all clean fclean re

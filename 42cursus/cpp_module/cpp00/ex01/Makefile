# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: balee <balee@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/22 16:28:11 by balee             #+#    #+#              #
#    Updated: 2022/11/22 19:27:13 by balee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= PhoneBook

CFLAGS		= -Wall -Werror -Wextra -std=c++98

INCS		= -I.
SRCS		= main.cpp PhoneBook.cpp Contact.cpp
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

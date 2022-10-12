# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: balee <balee@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/08 13:06:34 by balee             #+#    #+#              #
#    Updated: 2022/10/12 14:31:50 by balee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= philo

CC			= cc
CFLAG		= -Wall -Werror -Wextra
RM			= rm -f

INCS		= -I./include

SRC			= main.c init.c philo.c print.c util.c exit.c
SRCS		= $(addprefix ./srcs/, $(SRC))
OBJS		= $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAG) $(INCS) -o $(NAME) $(OBJS)

.c.o: $(SRC)
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
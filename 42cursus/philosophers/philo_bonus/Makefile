# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: balee <balee@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/15 17:17:01 by balee             #+#    #+#              #
#    Updated: 2022/10/17 17:55:56 by balee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= philo_bonus

CC			= cc
CFLAG		= -Wall -Werror -Wextra
RM			= rm -f

INCS		= -I./include

SRC			= main_bonus.c init_bonus.c philo_bonus.c util_bonus.c exit_bonus.c
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

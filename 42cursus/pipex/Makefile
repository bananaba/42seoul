# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: balee <balee@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/25 18:04:37 by balee             #+#    #+#              #
#    Updated: 2022/08/25 18:59:43 by balee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= pipex

CC			= cc
CFLAG		= -Wall -Werror -Wextra
RM			= rm -f

INCS		= -I./include
LIB			= ./Libft
LIB_FLAGS	= -L $(LIB) -l ft

SRCS		= $(addprefix ./src/, $(SRC))
OBJS		= $(SRCS:.c=.o)

ifdef BN
	SRC		= main_bonus.c pipe.c cmd.c path.c exit.c
else
	SRC		= main.c pipe.c cmd.c path.c exit.c
endif

all : $(OBJS) $(NAME)

$(NAME) : $(OBJS)
	make -C $(LIB) bonus
	$(CC) -o $(NAME) $(OBJS) $(LIB_FLAGS)

bonus:
	BN=1 make all

.c.o: $(SRCS)
	$(CC) $(CFLAG) $(INCS) -c -o $@ $<

clean :
	make -C ./Libft fclean
	$(RM) $(OBJS) ./src/main_bonus.o

fclean :
	make clean
	$(RM) $(NAME)

re :
	make fclean
	make all

PHONY : all clean fclean re bonus

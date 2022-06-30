# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: balee <balee@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/30 15:27:47 by balee             #+#    #+#              #
#    Updated: 2022/06/30 20:15:10 by balee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAG = -Wall -Wextra -Werror
NAME = push_swap
BONUS = checker
SRCS = avl_rot.c \
		avl.c \
		input.c \
		push.c \
		reverse_rotation.c \
		rotation.c \
		sort.c \
		swap.c \
		util.c \
		sort_a_util.c \
		sort_b_util.c
MAIN = push_swap.o
CHECKER = checker.o
HEADER = -I.
OBJS = $(SRCS:.c=.o)

all: $(NAME)

bonus: $(BONUS)

$(NAME): $(OBJS) $(MAIN)
	$(CC) $(FLAG) $(HEADER) -o $(NAME) $(MAIN) $(OBJS)

$(BONUS): $(OBJS) $(CHECKER)
	$(CC) $(FLAG) $(HEADER) -o $(BONUS) $(CHECKER) $(OBJS)

.c.o:
	$(CC) $(FLAG) $(HEADER) -c -o $@ $<

clean:
	rm -f $(OBJS) $(MAIN) $(CHECKER)

fclean: clean
	rm -f $(NAME) $(BONUS)

re: fclean all

.PHONY : all clean fclean re bonus
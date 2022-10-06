# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: balee <balee@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/30 15:27:47 by balee             #+#    #+#              #
#    Updated: 2022/07/06 04:49:16 by balee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
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
		sort3_a.c \
		sort3_b.c \
		sort4.c \
		sort5.c \
		sort_b_to_a.c \
		print_log.c \
		check_log.c \
		check_log_util.c
MAIN = push_swap.o
CHECKER = checker.o
HEADER = -I.
OBJS = $(SRCS:.c=.o)

all: $(NAME)

bonus: all $(BONUS)

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
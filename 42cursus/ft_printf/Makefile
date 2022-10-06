# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: balee <balee@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/15 17:30:14 by balee             #+#    #+#              #
#    Updated: 2022/03/15 17:58:15 by balee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAG = -Wall -Wextra -Werror -c
NAME = libftprintf.a
SRCS = ft_printf.c \
		ft_printf_util.c \
		ft_printf_char_str.c \
		ft_printf_num.c \
		ft_printf_num_util.c
HEADER = -I.
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $^

bonus: all

.c.o:
	$(CC) $(CFLAG) $(HEADER) -o $@ $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re bonus

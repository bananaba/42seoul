# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: balee <balee@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/08 13:06:34 by balee             #+#    #+#              #
#    Updated: 2023/01/29 17:43:41 by balee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= miniRT

CC			= cc
CFLAGS		= -Wall -Werror -Wextra
RM			= rm -f

INCS		= -I./includes
LIB			= ./Libft
LIB_FLAGS	= -L$(LIB) -lft
MLX_FLAGS	= -L./mlx -lmlx -framework OpenGL -framework Appkit

SRC = raytrace.c \
		vector.c

SRCS = $(addprefix ./srcs/, $(SRC))
OBJS = $(SRCS:.c=.o)

all : $(OBJS) $(NAME)

$(NAME) : $(OBJS)
	make -C ./mlx
	make -C $(LIB) bonus
	$(CC) $(CFLAGS) $(INCS) -o $(NAME) $(OBJS) $(MLX_FLAGS) $(LIB_FLAGS)

.c.o :
	$(CC) $(CFLAGS) $(INCS) -c -o $@ $<

clean :
	make -C ./mlx clean
	make -C ./Libft fclean
	$(RM) $(OBJS)

fclean :
	make clean
	$(RM) $(NAME)

re :
	make fclean
	make all

PHONY : all clean fclean re

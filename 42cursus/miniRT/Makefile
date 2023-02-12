# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: balee <balee@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/08 13:06:34 by balee             #+#    #+#              #
#    Updated: 2023/02/12 15:33:57 by balee            ###   ########.fr        #
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
		vector_util1.c \
		vector_util2.c \
		is_hitted.c \
		main.c \
		normal.c \
		position.c \
		raytracing_util1.c \
		rgb_util1.c \
		shadow_ray.c

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

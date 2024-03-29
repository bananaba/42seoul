# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: balee <balee@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/08 13:06:34 by balee             #+#    #+#              #
#    Updated: 2023/02/18 02:35:52 by balee            ###   ########.fr        #
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

SRC = camera_pos.c \
		exit.c \
		init_util1.c \
		init_util2.c \
		init_util3.c \
		init_util4.c \
		init_util5.c \
		init.c \
		is_hitted.c \
		main.c \
		math_functions.c\
		math_functions2.c\
		normal.c \
		position_util1.c \
		position_util2.c \
		position.c \
		raytrace.c \
		raytracing_util1.c \
		rgb_util1.c \
		set_obj1.c \
		set_obj2.c \
		set_obj3.c \
		set_obj4.c \
		shadow_ray.c \
		vector_util1.c \
		vector_util2.c \
		vector_util3.c

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

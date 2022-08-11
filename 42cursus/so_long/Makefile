NAME		= so_long

CC			= cc
CFLAG		= -Wall -Werror -Wextra
AR			= ar rcs
RM			= rm -f

INCS		= -I ./include
MLX_FLAGS	= -L ./mlx -lmlx -framework OpenGL -framework Appkit

SRC			=	so_long.c \
				map_check.c map_read.c map_draw.c\
				init_game.c \
				player.c \
				util.c
SRCS		= $(addprefix ./src/, $(SRC))
OBJS		= $(SRCS:.c=.o)

all : $(OBJS) $(NAME)

$(NAME) : $(OBJS)
	make -C ./mlx
	$(CC) -o $(NAME) $(OBJS) $(MLX_FLAGS)

.c.o:
	$(CC) $(CFLAG) $(INCS) -c -o $@ $<

clean :
	make -C ./mlx clean
	$(RM) $(OBJS)

fclean :
	make -C ./mlx clean
	make clean
	$(RM) $(NAME)

re :
	make fclean
	make all

PHONY : all clean fclean re $(NAME)
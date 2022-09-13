NAME		= so_long

CC			= cc
CFLAG		= -Wall -Werror -Wextra
RM			= rm -f

INCS		= -I./include
MLX_FLAGS	= -L./mlx -lmlx -framework OpenGL -framework Appkit

SRC			=	so_long.c \
				map_check.c map_read.c map_draw.c\
				init_game.c \
				player.c \
				util.c
SRC_BONUS	=	so_long_bonus.c \
				map_check_bonus.c map_read_bonus.c \
				map_draw_bonus.c step_draw_bonus.c\
				init_game_bonus.c \
				player_bonus.c \
				util_bonus.c
SRCS		= $(addprefix ./src/, $(SRC))
SRCS_BONUS	= $(addprefix ./src_bonus/, $(SRC_BONUS))
OBJS		= $(SRCS:.c=.o)
OBJS_BONUS	= $(SRCS_BONUS:.c=.o)

all : $(OBJS) $(NAME)

$(NAME) : $(OBJS)
	make -C ./mlx
	$(CC) $(CFLAG) $(INCS) -o $(NAME) $(OBJS) $(MLX_FLAGS)

bonus : $(OBJS_BONUS)
	make -C ./mlx
	$(CC) $(CFLAG) $(INCS) -o $(NAME) $(OBJS_BONUS) $(MLX_FLAGS)

.c.o :
	$(CC) $(CFLAG) $(INCS) -c -o $@ $<

clean :
	make -C ./mlx clean
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean :
	make -C ./mlx clean
	make clean
	$(RM) $(NAME)

re :
	make fclean
	make all

PHONY : all clean fclean re bonus

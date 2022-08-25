NAME		= pipex

CC			= cc
CFLAG		= -Wall -Werror -Wextra
RM			= rm -f

INCS		= -I./include
LIB			= ./Libft
LIB_FLAGS	= -L $(LIB) -l ft

SRC			= pipex.c cmd.c path.c				
SRCS		= $(addprefix ./src/, $(SRC))
OBJS		= $(SRCS:.c=.o)

all : $(OBJS) $(NAME)

$(NAME) : $(OBJS)
	make -C $(LIB) bonus
	$(CC) -o $(NAME) $(OBJS) $(LIB_FLAGS)

.c.o: $(SRC)
	$(CC) $(CFLAG) $(INCS) -c -o $@ $<

clean :
	make -C ./Libft fclean
	$(RM) $(OBJS)

fclean :
	make clean
	$(RM) $(NAME)

re :
	make fclean
	make all

PHONY : all clean fclean re

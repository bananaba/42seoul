NAME		= minishell

CC			= cc
CFLAG		= -Wall -Werror -Wextra -I ${HOME}/.brew/opt/readline/include
RM			= rm -f

INCS		= -I./includes
LIB			= ./Libft
LIB_FLAGS	= -L$(LIB) -lft -lreadline -L ${HOME}/.brew/opt/readline/lib

SRCS		= $(addprefix ./srcs/, $(SRC))
OBJS		= $(SRCS:.c=.o)

SRC			= main.c init.c mode.c read.c signal.c

all : $(OBJS) $(NAME)

$(NAME) : $(OBJS)
	make -C $(LIB) bonus
	$(CC) -o $(NAME) $(OBJS) $(LIB_FLAGS)

.c.o: $(SRCS)
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

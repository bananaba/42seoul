NAME		= philo

CC			= cc
CFLAG		= -Wall -Werror -Wextra
RM			= rm -f

INCS		= -I./include

SRC			= main.c init.c philo.c time.c print.c util.c exit.c
SRCS		= $(addprefix ./srcs/, $(SRC))
OBJS		= $(SRCS:.c=.o)

all : $(OBJS) $(NAME)

$(NAME) : $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

.c.o: $(SRC)
	$(CC) $(CFLAG) $(INCS) -c -o $@ $<

clean :
	$(RM) $(OBJS)

fclean :
	make clean
	$(RM) $(NAME)

re :
	make fclean
	make all

PHONY : all clean fclean re
NAME		= BraiiiiiiinnnzzzZ

CC			= c++
CFLAG		= -Wall -Werror -Wextra -std=c++98
RM			= rm -f

INCS		= -I.
SRC			= main Zombie newZombie randomChump
SRCS		= $(addprefix $(SRC), .cpp)
OBJS		= $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAG) -o $(NAME) $(OBJS)

.cpp.o: $(SRC)
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

NAME		= BraiiiiiiinnnzzzZ

CXX			= c++
CXXFLAGS	= -Wall -Werror -Wextra -std=c++98

INCS		= -I.
SRC			= main Zombie newZombie randomChump
SRCS		= $(addprefix $(SRC), .cpp)
OBJS		= $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

.cpp.o: $(SRC)
	$(CXX) $(CXXFLAGs) $(INCS) -c -o $@ $<

clean :
	$(RM) $(OBJS)

fclean :
	make clean
	$(RM) $(NAME)

re :
	make fclean
	make all

PHONY : all clean fclean re

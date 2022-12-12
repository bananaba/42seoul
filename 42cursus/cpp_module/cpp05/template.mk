ifndef NAME
	NAME		= a.out
endif

CXX				= c++

ifndef CXXFLAGS
	CXXFLAGS	= -Wall -Werror -Wextra -std=c++98
endif

INCS			= -I.

ifndef SRCS
	SRCS		= main.c
endif

OBJS			= $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

.cpp.o: $(SRC)
	$(CXX) $(CXXFLAGS) $(INCS) -c -o $@ $<

clean :
	$(RM) $(OBJS)

fclean :
	make clean
	$(RM) $(NAME)

re :
	make fclean
	make all

PHONY : all clean fclean re

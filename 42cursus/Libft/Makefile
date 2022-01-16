CC = gcc
CFLAG = -Wall -Wextra -Werror -c
NAME = *.c
HEADER = -I.
OBJS = $(NAME:.c=.o)

all: libft.a

libft.a: $(OBJS)
	ar rcs libft.a $(OBJS)

%.o: %.c
	$(CC) $(CFLAG) $< -o $@ $(HEADER)

$(NAME):
	$(CC) $(CFLAG) $(OBJS) -o $< $(HEADER)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f libft.a

re: fclean all
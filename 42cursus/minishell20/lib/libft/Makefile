# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snoh <snoh@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/30 20:55:37 by snoh              #+#    #+#              #
#    Updated: 2022/10/24 22:20:29 by snoh             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g
AR		= ar
ARFLAGS	= -rc


NAME = libftprintf.a
#EXCUTABLE = a.out

PART1 =	ft_isalpha				\
		ft_isdigit				\
		ft_isalnum				\
		ft_isascii				\
		ft_isprint				\
		ft_isquote				\
		ft_isspace				\
		ft_strlen				\
		ft_memset				\
		ft_bzero				\
		ft_memcpy				\
		ft_memmove				\
		ft_strlcpy				\
		ft_strlcat				\
		ft_toupper				\
		ft_tolower				\
		ft_strchr				\
		ft_strrchr				\
		ft_strncmp				\
		ft_memchr				\
		ft_memcmp				\
		ft_strnstr				\
		ft_atoi					\
		ft_calloc				\
		ft_strdup
		

PART2 =	ft_substr				\
		ft_strjoin				\
		ft_strtrim				\
		ft_split				\
		ft_itoa					\
		ft_strmapi				\
		ft_striteri				\
		ft_putchar_fd			\
		ft_putstr_fd			\
		ft_putendl_fd			\
		ft_putnbr_fd

BONAS = ft_lstnew				\
		ft_lstadd_front			\
		ft_lstsize				\
		ft_lstlast				\
		ft_lstadd_back			\
		ft_lstdelone			\
		ft_lstclear				\
		ft_lstiter				\
		ft_lstmap

PRINTF= ft_printf				\
		ft_sprintf				\
		ft_mprintf				\
        ft_str_djoin			\
        ft_str_nreplace			\
        ft_printf_conversions1	\
        ft_printf_conversions2	\
        ft_printf_conversions3	\
        ft_printf_checks		\
        ft_strdupc				

ADDIT = ft_lst_something1		\
		ft_strlen_c				\
		ft_strlen_s				\
		ft_int_max				\
		ft_int_min				\
		ft_lstdel_next			\




OBJ			= $(addsuffix .o, $(PART1) $(PART2) $(BONAS) $(PRINTF) $(ADDIT))
BONUS_OBJ	= $(addsuffix _bonus.o, $(BONAS))



all : $(NAME)

$(NAME) : $(OBJ)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ)

#bonus : $(OBJ) $(BONUS_OBJ)
#	$(AR) $(ARFLAGS) $(NAME) $(OBJ) $(BONUS_OBJ)

#$(EXCUTABLE) : main

clean :
	rm -f *.o

fclean : clean
	rm -f $(NAME)
#	rm -f $(EXCUTABLE)

re : clean all

#main : all main.o
#	$(CC) $(CFLAGS) -o $(EXCUTABLE) main.o $(OBJ)

#run : main
#	./$(EXCUTABLE)

#debug : main
#	lldb $(EXCUTABLE)

.PHONY : all clean fclean re #main run debug bonus

%.o : %.c
	$(CC) $(CFLAGS) -c $<
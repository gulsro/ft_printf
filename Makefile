NAME = libftprintf.a

SRC = ./libftprintf/ft_putchar.c \
	./libftprintf/ft_putnbr.c \
	./libftprintf/ft_strlen.c \
	./libftprintf/ft_putstr.c \
	./libftprintf/ft_puthexlow.c \
	./libftprintf/ft_puthexupp.c \
	./libftprintf/ft_putaddr.c \
	./libftprintf/ft_putunsigned.c \
	ft_printf.c

CC = cc

CFLAGS = -Wall -Werror -Wextra -I "." 

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
			ar rc $@ $?

clean :
			rm -f *.o ./libftprintf/*.o

fclean :        clean
			rm -f $(NAME)

re : fclean all

.PHONY = all clean fclean re

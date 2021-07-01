##
## EPITECH PROJECT, 2018
## makefile
## File description:
## makefile
##

SRC		=		src/main.c				\
				src/player1.c			\
				src/player2.c			\
				src/boat.c				\
				src/load_file.c			\
				src/signal.c			\
				src/tab.c				\
				src/send_get.c			\
				src/left.c				\
				src/check_coord.c		\
				src/check_part.c		\
				src/lib/convert_print.c	\
				src/lib/my_getnbr.c		\
				src/lib/my_in.c			\
				src/lib/my_itos.c		\
				src/lib/my_printf.c		\
				src/lib/my_put_nbr.c	\
				src/lib/my_putchar.c	\
				src/lib/my_putstr.c		\
				src/lib/my_revstr.c		\
				src/lib/my_strcmp.c		\
				src/lib/my_strlowcase.c	\
				src/lib/my_strcpy.c		\
				src/lib/put_unsigned.c	\
				src/lib/simple_print.c	\
				src/lib/my_strlen.c

CFLAGS		=	-I include/

CC			=	gcc -no-pie

OBJ			=	$(SRC:.c=.o)

NAME		=	navy

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)
	rm -f *.o

fclean:	clean
	rm -f $(NAME)
	rm -f unit_tests

re:	fclean all

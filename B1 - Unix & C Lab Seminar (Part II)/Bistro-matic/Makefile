##
## EPITECH PROJECT, 2018
## makefile
## File description:
## makefile
##

SRC	=	src/main.c			\
		src/get_error.c		\
		src/misc.c			\
		calcul/mult.c		\
		calcul/infin_add.c	\
		calcul/script.c		\
		calcul/tool.c

FLAG	=	-g -Llib/my -lmy -Iinclude

NAME	=	calc

all:
	make -C ./lib/my
	gcc -c $(SRC)
	gcc -g -o $(NAME) *.o $(FLAG)

clean:
	make -C ./lib/my clean
	rm -f *.o

fclean:	clean
	make -C ./lib/my fclean
	rm -f $(NAME)

re:	fclean all

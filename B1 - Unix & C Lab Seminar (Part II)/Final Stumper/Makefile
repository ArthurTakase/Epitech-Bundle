##
## EPITECH PROJECT, 2018
## makefile
## File description:
## makefile
##

SRC	=	main.c	\
		rush3.c	\
		tools.c	\
		size.c

FLAG	=	-g -Llib/my -lmy -Iinclude

NAME	=	rush3

all:	$(OBJ)
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

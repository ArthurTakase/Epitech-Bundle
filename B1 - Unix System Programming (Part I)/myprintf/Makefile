##
## EPITECH PROJECT, 2018
## makefile
## File description:
## makefile
##

SRC			=	src/main.c				\
				src/simple_print.c		\
				src/convert_print.c		\
				src/my_itos.c			\
				src/put_unsigned.c		\
				src/my_put_nbr.c		\
				src/my_putchar.c		\
				src/my_putstr.c			\
				src/my_revstr.c			\
				src/my_strlowcase.c

OBJ			=	$(SRC:.c=.o)

DIR_GCOVR	=	gcovr/

NAME		=	libmy.a

all: $(OBJ)
	gcc -c $(SRC)
	ar rc $(NAME) $(OBJ)
	mkdir -p ./include
	cp src/my.h ./include/

clean:
	rm -f $(OBJ)
	cd ..
	rm -f *.o
	rm -f *.gcno
	rm -f *.gcda

fclean:	clean
	make -C ./lib/my fclean
	rm -f lib/libmy.a
	rm -f $(NAME)
	rm -f unit_tests

re:	fclean all

test:
	gcc -o unit_tests ${SRC} ${FLAG} tests/tests.c --coverage -lcriterion
	./unit_tests

gcovr: test
	mkdir -p $(DIR_GCOVR) && cd $(DIR_GCOVR); \
		gcovr --root ../ --exclude "../tests" --html --html-details --html-title $(NAME) -o $(NAME).html

##
## EPITECH PROJECT, 2018
## makefile
## File description:
## makefile
##

SRC			=	src/main.c		\
				src/l_option.c	\
				src/parse.c

LDFLAGS		=	-Llib/my -lmy

CFLAGS		=	-Iinclude

OBJ			=	$(SRC:.c=.o)

DIR_GCOVR	=	gcovr/

NAME		=	my_ls

TESTS		=	$(SRC)\
				tests/test.c

T_OBJ		=	$(TESTS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./lib/my
	gcc -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS) lib/printf.a

lib:
	$(MAKE) -C ./lib/my re

clean:
	make -C ./lib/my clean
	rm -f $(OBJ)
	rm -f *.o
	rm -f *.gcno
	rm -f *.gcda

fclean:	clean
	make -C ./lib/my fclean
	rm -f lib/libmy.a
	rm -f $(NAME)
	rm -f unit_tests

re:	fclean all

test: $(T_OBJ)
	make -C ./lib/my
	gcc -o unit_tests ${SRC} -Llib/my -lmy -Iinclude tests/test.c --coverage -lcriterion
	./unit_tests

gcovr: test
	mkdir -p $(DIR_GCOVR) && cd $(DIR_GCOVR); \
		gcovr --root ../ --exclude "../tests" --html --html-details --html-title $(NAME) -o $(NAME).html

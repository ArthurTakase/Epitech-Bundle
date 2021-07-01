##
## EPITECH PROJECT, 2018
## makefile
## File description:
## makefile
##

SRC			=	src/main.c		\
				src/list_p1.c	\
				src/list_p2.c	\
				src/move.c		\
				src/my_getnbr.c	\
				src/my_putstr.c	\
				src/my_strlen.c	\
				src/check.c		\
				src/start.c

SRC_TEST	=	src/list_p1.c	\
				src/list_p2.c	\
				src/move.c		\
				src/my_getnbr.c	\
				src/my_putstr.c	\
				src/my_strlen.c	\
				src/check.c		\
				src/start.c

CFLAGS		=	-Iinclude

DIR_GCOVR	=	gcovr/

OBJ			=	$(SRC:.c=.o)

TESTS		=	$(SRC_TEST)\
				tests/test.c

T_OBJ		=	$(TESTS:.c=.o)

NAME		=	push_swap

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)
	rm -f *.gcno
	rm -f *.gcda
	cd tests/
	rm -f *.o

fclean:	clean
	rm -f $(NAME)
	rm -f unit_tests

re:	fclean all

tests_run: $(T_OBJ)
	gcc -o unit_tests ${SRC_TEST} tests/test.c --coverage -lcriterion
	./unit_tests

gcovr: tests_run
	mkdir -p $(DIR_GCOVR) && cd $(DIR_GCOVR); \
		gcovr --root ../ --exclude "../tests" --html --html-details --html-title $(NAME) -o $(NAME).html
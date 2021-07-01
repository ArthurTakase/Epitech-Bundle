##
## EPITECH PROJECT, 2018
## makefile
## File description:
## makefile
##

SRC		=	src/main.c		\
			src/my_strlen.c		\
			src/my_putstr.c		\
			src/my_putchar.c	\
			src/clean_str.c

SRC_TEST	=	src/my_strlen.c		\
			src/my_putstr.c		\
			src/my_putchar.c	\
			src/clean_str.c

CFLAGS		=	-Iinclude -W -Wall -Wextra

CC		=	gcc

DIR_GCOVR	=	gcovr/

OBJ		=	$(SRC:.c=.o)

TESTS		=	$(SRC_TEST)\
			tests/test.c

T_OBJ		=	$(TESTS:.c=.o)

NAME		=	clean_str

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)
	rm -f *.gcno
	rm -f *.gcda

fclean:	clean
	rm -f $(NAME)
	rm -f unit_tests

re:	fclean all

tests_run: $(T_OBJ)
	$(CC) -o unit_tests ${SRC_TEST} -Iinclude tests/test.c --coverage -lcriterion
	./unit_tests

gcovr: tests_run
	mkdir -p $(DIR_GCOVR) && cd $(DIR_GCOVR); \
		gcovr --root ../ --exclude "../tests" --html --html-details --html-title $(NAME) -o $(NAME).html

##
## EPITECH PROJECT, 2018
## makefile
## File description:
## makefile
##

#SRC_LIB		=	# à remplir

SRC			=	src/stumper.c		\
				src/tail.c			\
				src/my_putstr.c		\
				src/my_strlen.c		\
				src/list_p1.c		\
				src/list_p2.c		\
				src/tail_part.c		\
				src/my_revstr.c		\
				src/my_strncmp.c	\
				src/my_strcmp.c		\
				src/my_getnbr.c		\
				src/my_str_isnum.c	\
				src/my_in.c

SRC_ALL		=	$(SRC)				\
				src/main.c

TESTS		=	$(SRC)				\
				tests/test.c

CFLAGS		=	-W -Wall -Wextra

CPPFLAGS	=	-Iinclude

CC			=	gcc -g

DIR_GCOVR	=	gcovr/

OBJ			=	$(SRC_ALL:.c=.o)

T_OBJ		=	$(TESTS:.c=.o)

NAME		=	stumper

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)
	rm -f $(T_OBJ)
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
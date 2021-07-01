##
## EPITECH PROJECT, 2018
## makefile
## File description:
## makefile
##

SRC_LIB		=	src/lib/my_getnbr.c				\
				src/lib/my_str_isnum.c			\
				src/lib/my_strlen.c				\
				src/lib/my_putstr.c				\
				src/lib/clonestr.c				\
				src/lib/my_put_nbr.c			\
				src/lib/my_getline.c			\
				src/lib/how_many_in.c

SRC			=	$(SRC_LIB)						\
				src/matchstick.c				\
				src/map.c						\
				src/player/player.c				\
				src/player/line.c				\
				src/player/matche.c				\
				src/remove_from_line.c			\
				src/ia/ia.c

SRC_ALL		=	$(SRC)							\
				src/main.c

TESTS		=	$(SRC)							\
				tests/test.c

CFLAGS		=	-W -Wall -Wextra

CPPFLAGS	=	-Iinclude

CC			=	gcc -g

DIR_GCOVR	=	gcovr/

OBJ			=	$(SRC_ALL:.c=.o)

T_OBJ		=	$(TESTS:.c=.o)

NAME		=	matchstick

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
##
## EPITECH PROJECT, 2018
## makefile
## File description:
## makefile
##

SRC_LIB		=	src/lib/read_file.c				\
				src/lib/itos_base.c				\
				src/lib/my_revstr.c				\
				src/lib/my_strncat.c			\
				src/lib/my_strlen.c				\
				src/lib/my_in.c					\
				src/lib/my_strcmp.c				\
				src/lib/my_putstr.c

SRC			=	$(SRC_LIB)						\
				src/sokoban.c					\
				src/player/player_move.c		\
				src/player/player.c				\
				src/player/player_move_part.c	\
				src/map/map.c					\
				src/map/clone_map.c				\
				src/map/print_map.c				\
				src/error.c						\
				src/box/box.c					\
				src/usage.c						\
				src/end.c

SRC_ALL		=	$(SRC)							\
				src/main.c

TESTS		=	$(SRC)							\
				tests/test.c

CFLAGS		=	-W -Wall -Wextra

CPPFLAGS	=	-Iinclude

CC			=	gcc -g -no-pie

DIR_GCOVR	=	gcovr/

OBJ			=	$(SRC_ALL:.c=.o)

T_OBJ		=	$(TESTS:.c=.o)

NAME		=	my_sokoban

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) -lncurses

clean:
	rm -f $(OBJ)
	rm -f $(T_OBJ)
	cd src/lib/ && rm -f *.o
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
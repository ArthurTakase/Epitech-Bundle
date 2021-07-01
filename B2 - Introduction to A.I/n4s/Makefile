##
## EPITECH PROJECT, 2021
## B-MUL-200-BDX-2-1-mydefender-arthur.decaen
## File description:
## Makefile
##

SRC_LIB		=	src/lib/my_in.c			\
				src/lib/split_str.c		\
				src/lib/my_putstr.c		\
				src/lib/my_strcmp.c		\
				src/lib/len_array.c

SRC			=	$(SRC_LIB)				\
				src/ia.c				\
				src/move.c				\
				src/infos.c

SRC_ALL		=	$(SRC)					\
				src/main.c

CFLAGS		=	-W -Wall -Wextra

CPPFLAGS	=	-Iinclude

CC			=	gcc -no-pie

DIR_GCOVR	=	gcovr/

OBJ			=	$(SRC_ALL:.c=.o)

NAME		=	ai

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)
	rm -f *.gcno
	rm -f *.gcda

fclean:	clean
	rm -f $(NAME)
	rm -f unit_tests

re:	fclean all

tests_run: $(T_OBJ)
	$(CC) -o unit_tests ${SRC} -Iinclude tests/test.c --coverage -lcriterion
	./unit_tests

gcovr: tests_run
	mkdir -p $(DIR_GCOVR) && cd $(DIR_GCOVR); \
		gcovr --root ../ --exclude "../tests" --html --html-details --html-title $(NAME) -o $(NAME).html
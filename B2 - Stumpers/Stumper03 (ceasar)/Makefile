##
## EPITECH PROJECT, 2018
## makefile
## File description:
## makefile
##

#SRC_LIB		=	# à remplir

SRC			=	src/encrypt.c		\
				src/lib/my_getnbr.c	\
				src/lib/my_str_isnum.c	\
				src/lib/read_file.c

SRC_ALL		=	$(SRC)				\
				src/main.c

CFLAGS		=	-W -Wall -Wextra

CPPFLAGS	=	-Iinclude

CC			=	gcc -g

DIR_GCOVR	=	gcovr/

OBJ			=	$(SRC_ALL:.c=.o)

NAME		=	cesar

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
	$(CC) -o unit_tests ${SRC} -Iinclude tests/test.c --coverage -lcriterion
	./unit_tests

gcovr: tests_run
	mkdir -p $(DIR_GCOVR) && cd $(DIR_GCOVR); \
		gcovr --root ../ --exclude "../tests" --html --html-details --html-title $(NAME) -o $(NAME).html
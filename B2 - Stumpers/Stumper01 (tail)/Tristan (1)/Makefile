##
## EPITECH PROJECT, 2018
## makefile
## File description:
## makefile
##

SRC_LIB		=	temp/lib/my_strlen.c	\
				temp/lib/my_getnbr.c	\
				temp/lib/my_strcmp.c	\
				temp/lib/my_strncmp.c

SRC			=	src/stumper.c		\
# 				src/error.c

SRC_ALL		=	src/main.c

TESTS		=	$(SRC)				\
				tests/test.c

CFLAGS		=	-W -Wall -Wextra

CPPFLAGS	=	-Iinclude

CC			=	gcc -g

DIR_GCOVR	=	gcovr/

OBJ			=	$(SRC_ALL:.c=.o) $(SRC:.c=.o) $(SRC_LIB:.c=.o)

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
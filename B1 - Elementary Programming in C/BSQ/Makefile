##
## EPITECH PROJECT, 2018
## makefile
## File description:
## makefile
##

SRC			=	src/load_2d.c		\
				src/load_file.c		\
				src/main.c			\
				src/read_file.c		\
				src/len_array.c		\
				src/create_dup.c	\
				src/set_value.c		\
				src/set_x.c			\
				src/start.c

SRC_TEST	=	src/load_2d.c		\
				src/load_file.c		\
				src/read_file.c		\
				src/len_array.c		\
				src/create_dup.c	\
				src/set_value.c		\
				src/set_x.c			\
				src/start.c

LDFLAGS		=	-Llib/my -lmy

CFLAGS		=	-Iinclude

OBJ			=	$(SRC:.c=.o)

DIR_GCOVR	=	gcovr/

NAME		=	bsq

TESTS		=	$(SRC)\
				tests/test.c

T_OBJ		=	$(TESTS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./lib/my
	gcc -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS)

lib:
	$(MAKE) -C ./lib/my re

clean:
	make -C ./lib/my clean
	rm -f $(OBJ)
	rm -f *.o
	rm -f *.gcno
	rm -f *.gcda
	cd tests/
	rm -f *.o

fclean:	clean
	make -C ./lib/my fclean
	rm -f lib/libmy.a
	rm -f $(NAME)
	rm -f unit_tests

re:	fclean all

test_run: $(T_OBJ)
	make -C ./lib/my
	gcc -o unit_tests ${SRC_TEST} -Llib/my -lmy -Iinclude tests/test.c --coverage -lcriterion
	./unit_tests

gcovr: test_run
	mkdir -p $(DIR_GCOVR) && cd $(DIR_GCOVR); \
		gcovr --root ../ --exclude "../tests" --html --html-details --html-title $(NAME) -o $(NAME).html

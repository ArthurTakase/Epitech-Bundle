##
## EPITECH PROJECT, 2018
## makefile
## File description:
## makefile
##

SRC		=		src/main.c					\
				src/game.c					\
				src/event.c					\
				src/draw.c					\
				src/check_duck.c			\
				src/check_dog.c				\
				src/init/init_graph.c		\
				src/init/init_dog.c			\
				src/init/init_misc.c		\
				src/init/init_sound.c		\
				lib/my_itos.c				\
				lib/my_revstr.c

LDFLAGS		=	-lcsfml-graphics -lcsfml-window -l csfml-system -lcsfml-audio

CFLAGS		=	-Iinclude -W -Wall -Wextra

CC			=	gcc

OBJ			=	$(SRC:.c=.o)

DIR_GCOVR	=	gcovr/

NAME		=	my_hunter

TESTS		=	$(SRC)\
				tests/test.c

T_OBJ		=	$(TESTS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) lib/libmy.a

clean:
	rm -f $(OBJ)
	rm -f *.o
	rm -f *.gcno
	rm -f *.gcda

fclean:	clean
	rm -f lib/libmy.a
	rm -f $(NAME)
	rm -f unit_tests

re:	fclean all

test: $(T_OBJ)
	gcc -o unit_tests ${SRC} -Llib/my -lmy -Iinclude tests/test.c --coverage -lcriterion
	./unit_tests

gcovr: test
	mkdir -p $(DIR_GCOVR) && cd $(DIR_GCOVR); \
		gcovr --root ../ --exclude "../tests" --html --html-details --html-title $(NAME) -o $(NAME).html
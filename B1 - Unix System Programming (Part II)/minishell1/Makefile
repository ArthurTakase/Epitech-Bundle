##
## EPITECH PROJECT, 2018
## makefile
## File description:
## makefile
##

SRC_LIB		=	lib/my_putstr.c						\
				lib/my_strcmp.c						\
				lib/my_strlen.c						\
				lib/clonestr.c						\
				lib/my_strcat.c						\
				lib/my_in.c

SRC			=	$(SRC_LIB)							\
				src/main.c							\
				src/minishell.c						\
				src/arg.c							\
				src/execute/exe.c					\
				src/execute/exe_built.c				\
				src/execute/exe_bash.c				\
				src/path.c							\
				src/built_in/env.c					\
				src/built_in/setenv.c				\
				src/built_in/unsetenv.c				\
				src/built_in/cd.c					\
				src/built_in/get_env.c				\
				src/set_prompt.c

SRC_TEST	=	$(SRC_LIB)							\
				src/minishell.c						\
				src/arg.c							\
				src/execute/exe.c					\
				src/execute/exe_built.c				\
				src/execute/exe_bash.c				\
				src/path.c							\
				src/built_in/env.c					\
				src/built_in/setenv.c				\
				src/built_in/unsetenv.c				\
				src/built_in/cd.c					\
				src/built_in/get_env.c				\
				src/set_prompt.c

TESTS		=	$(SRC_TEST)							\
				tests/test.c

CFLAGS		=	-W -Wall -Wextra -fno-builtin-memset

CPPFLAGS	=	-Iinclude

CC			=	gcc -g

DIR_GCOVR	=	gcovr/

OBJ			=	$(SRC:.c=.o)

T_OBJ		=	$(TESTS:.c=.o)

NAME		=	mysh

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
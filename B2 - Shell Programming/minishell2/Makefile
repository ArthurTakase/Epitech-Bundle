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
				lib/my_in.c							\
				lib/clean_str.c						\
				lib/error.c							\
				lib/print_array.c					\
				lib/free_array.c					\
				lib/len_array.c						\
				lib/my_error.c						\
				lib/linked_list/dlist_add.c			\
				lib/linked_list/dlist_remove.c		\
				lib/linked_list/dlist.c				\
				lib/strpart.c

SRC_ALL		=	$(SRC_LIB)							\
				src/minishell.c						\
				src/arg_dlist.c						\
				src/signal.c						\
				src/execute/exe.c					\
				src/execute/exe_built.c				\
				src/execute/exe_bash.c				\
				src/path.c							\
				src/built_in/env.c					\
				src/built_in/setenv.c				\
				src/built_in/unsetenv.c				\
				src/built_in/cd.c					\
				src/built_in/get_env.c				\
				src/set_prompt.c					\
				src/built_in/cd_part.c				\
				src/built_in/pwd.c					\
				src/shell2/stdout.c					\
				src/shell2/pipe.c					\
				src/shell2/stdin.c					\
				src/loop_shell.c

SRC			=	$(SRC_ALL)							\
				src/main.c

CFLAGS		=	-W -Wall -Wextra -fno-builtin-memset

CPPFLAGS	=	-Iinclude

CC			=	gcc -g

DIR_GCOVR	=	gcovr/

OBJ			=	$(SRC:.c=.o)

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
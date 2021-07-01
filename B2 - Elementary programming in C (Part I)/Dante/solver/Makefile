##
## EPITECH PROJECT, 2018
## makefile
## File description:
## makefile
##

SRC			=	errors/error_handling.c 		\
				init/init.c 					\
				init/init_solution_tab.c 		\
				main.c 							\
				solve_maze/solve_maze.c 		\
				solve_maze/apply_solution.c 	\
				solver.c 						\
				tools/display_tools.c 			\
				tools/tools.c 					\
				usage/usage.c

CC			=	gcc

RM 			= 	rm -f

DIR_GCOVR	=	gcovr/

OBJ_DIR 	= 	src
OBJ			=	$(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

NAME		=	solver

CFLAGS		=	-W -Wall -Wextra

CPPFLAGS	=	-I./include/

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $@ $^

tests_run: fclean
	make -C tests/

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)
	make -C tests/ $@

re:	fclean all

gcovr: tests_run
	mkdir -p $(DIR_GCOVR) && cd $(DIR_GCOVR); \
		gcovr --root ../ --exclude "../tests" --html --html-details --html-title $(NAME) -o $(NAME).html

.PHONY: all clean fclean tests_run re gcovr

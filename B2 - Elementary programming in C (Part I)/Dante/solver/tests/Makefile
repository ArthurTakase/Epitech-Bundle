#
## EPITECH PROJECT, 2021
## Test Makefile
## File description:
## Makefile
#

SRC    = 		../src/errors/error_handling.c 			\
				../src/init/init.c 						\
				../src/init/init_solution_tab.c 		\
				../src/solve_maze/solve_maze.c 			\
				../src/solve_maze/apply_solution.c 		\
				../src/solver.c 						\
				../src/tools/display_tools.c 			\
				../src/tools/tools.c 					\
				../src/usage/usage.c 					\
				test_error_handling.c 					\
				test_init.c 							\
				test_solver.c 							\
				redirect_all_std.c

CC  		= 	gcc
RM 			= 	rm -f

OBJ 		= 	$(SRC:.c=.o)

NAME 		= 	unit-tests

CFLAGS 		= 	-I../include --coverage
LDFLAGS 	= 	-lcriterion

all: 	$(NAME)

$(NAME): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)
	./$(NAME)
	$(RM) $(OBJ)

fclean:
	$(RM) $(NAME)
	$(RM) $(OBJ)
	find ../ -type f -name "*.gc*" -delete

.PHONY: all clean fclean

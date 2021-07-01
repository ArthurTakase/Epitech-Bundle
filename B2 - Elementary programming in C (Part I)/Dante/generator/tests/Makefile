#
## EPITECH PROJECT, 2021
## Test Makefile
## File description:
## Makefile
#

SRC    = 		redirect_all_std.c

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

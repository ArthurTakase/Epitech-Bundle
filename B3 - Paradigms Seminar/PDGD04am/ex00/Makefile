##
## EPITECH PROJECT, 2022
## B-PDG-300-BDX-3-1-PDGD04am-arthur.decaen
## File description:
## Makefile
##

SRC			=	z.c

CFLAGS		=	-W -Wall -Wextra -std=gnu17

CPPFLAGS	=	-Iinclude

CC			=	gcc -g

OBJ			=	$(SRC:.c=.o)

NAME		=	z

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

.PHONY: all clean fclean re $(NAME)

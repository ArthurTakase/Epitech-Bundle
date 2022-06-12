##
## EPITECH PROJECT, 2022
## B-PDG-300-BDX-3-1-PDGD02-arthur.decaen
## File description:
## Makefile
##

SRC			=	DoOp.hs

CFLAGS		=	-W -Wall -Wextra

CC			=	ghc -g

OBJ			=	$(SRC:.c=.o)

NAME		=	doop

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean:
	rm -f *.o
	rm -f *.hi
	rm -f $(NAME)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
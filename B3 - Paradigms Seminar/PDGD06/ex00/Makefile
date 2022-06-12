##
## EPITECH PROJECT, 2022
## B-PDG-300-BDX-3-1-PDGD06-arthur.decaen
## File description:
## Makefile
##

SRC			=	ex00.cpp

CFLAGS		=	-std=c++20 -Wall -Wextra -Werror

CC			=	g++

OBJ			=	$(SRC:.cpp=.o)

NAME		=	my_cat

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)
	rm -f *.gcno
	rm -f *.gcda

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re $(NAME)
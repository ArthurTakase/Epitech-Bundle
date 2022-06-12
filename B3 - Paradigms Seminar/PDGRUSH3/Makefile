##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC_ALL		=	src/main.cpp					\
				src/Ncurses/DisplayNcurses.cpp	\
				src/SFML/DisplaySFML.cpp

CPPFLAGS	=	-W -Wall -Wextra -lcurses

CC			=	g++ -g -no-pie

OBJ			=	$(SRC_ALL:.c=.o)

NAME		=	MyGKrellm

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) -lncurses -lsfml-graphics -lsfml-window -lsfml-system

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: $(NAME) all clean fclean re
##
## EPITECH PROJECT, 2018
## makefile
## File description:
## makefile
##

SRC		=   string.c	\
			string_1.c	\
			string_2.c	\
			string_3.c

OBJ     =   $(SRC:.c=.o)

NAME    =   libstring.a

all:    $(NAME)

$(NAME):    $(OBJ)
	ar rc $(NAME) $(OBJ)
	cp my.h string.h

clean:
	rm -f $(OBJ)

fclean: clean
	rm -Rf $(NAME)

re: fclean all

.PHONI: all $(NAME) clean fclean re
##
## EPITECH PROJECT, 2020
## makefile
## File description:
## makefile
##

SRCC	=	*.c

SRCO	=	*.o

NAME    =       libmy.a

all: $(NAME)

$(NAME):
	gcc -c $(SRCC)
	ar rc $(NAME) $(SRCO)
	cp $(NAME) ./../
	mkdir -p ./../../include
	cp my.h ./../../include/

clean:
		rm -f $(SRCO)

fclean: clean
		rm -rf $(NAME)

re: fclean all

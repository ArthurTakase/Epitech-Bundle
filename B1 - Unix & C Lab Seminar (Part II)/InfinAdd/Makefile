##
## EPITECH PROJECT, 2018
## makefile
## File description:
## makefile
##

SRCS	=	calcul.c	\
			main.c		\
			choice.c	\
			tools.c

NAME	= infin_add

OBJS	= $(SRCS:.c=.o)

$(NAME):	$(OBJS)
	cc $(OBJS) -o $(NAME) lib/libmy.a

all:	$(NAME)

clean:
	rm -rf $(OBJS)

fclean:		clean
	rm -rf $(NAME)

re:	fclean all

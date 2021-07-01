
##
## EPITECH PROJECT, 2018
## makefile
## File description:
## makefile
##

SRCS	=	calcul.c	\
			do_op.c

NAME	= 	do-op

OBJS	= 	$(SRCS:.c=.o)

$(NAME):	$(OBJS)
	cc $(OBJS) -o $(NAME) ../lib/libmy.a

all:	$(NAME)

clean:
	rm -rf $(OBJS)

fclean:		clean
	rm -rf $(NAME)

re:	fclean all

##
## EPITECH PROJECT, 2022
## B-CCP-400-BDX-4-1-panoramix-arthur.decaen
## File description:
## Makefile
##

SRC		=	src/panoramix.c		\
			src/args.c			\
			src/villager.c		\
			src/druid.c

CFLAGS	=	-Wall -Wextra -Wno-deprecated -Iinclude -lpthread

OBJS	=	$(SRC:.c=.o)

NAME	=	panoramix

all:	$(NAME)

$(NAME): $(OBJS)
	gcc -g -o $(NAME) $(OBJS) $(CFLAGS)

clean:
	@rm -rf $(OBJS)

fclean:	clean
	@rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re

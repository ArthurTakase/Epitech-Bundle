##
## EPITECH PROJECT, 2022
## B-PSU-400-BDX-4-1-malloc-arthur.decaen [WSL: Ubuntu-20.04]
## File description:
## Makefile
##

SRC		=	src/malloc.c		\
			src/block.c			\
			src/calloc.c		\
			src/free.c			\
			src/realloc.c

CFLAGS	=	-Wall -Wextra -Wno-deprecated -fPIC -Iinclude

OBJS	=	$(SRC:.c=.o)

NAME	=	libmy_malloc.so

all:	$(NAME)

$(NAME): $(OBJS)
	gcc -shared -o $(NAME) $(OBJS) $(CFLAGS)

clean:
	rm -rf $(OBJS)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

launch: re clean
	LD_PRELOAD=./libmy_malloc.so ./a.out

.PHONY: all clean fclean re
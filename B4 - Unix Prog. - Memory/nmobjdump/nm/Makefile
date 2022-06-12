##
## EPITECH PROJECT, 2022
## B-PSU-400-BDX-4-1-nmobjdump-arthur.decaen
## File description:
## Makefile
##

SRC_CORE	=	core/check_header.c

SRC		=	$(SRC_CORE)			\
			src/nm.c			\
			src/get_type.c		\
			src/manage_symb.c

CFLAGS	=	-Wall -Wextra -Wno-deprecated -Iinclude

OBJS	=	$(SRC:.c=.o)

NAME	=	my_nm

all:	$(NAME)

$(NAME): $(OBJS)
	gcc -g -o $(NAME) $(OBJS) $(CFLAGS)

clean:
	@rm -rf $(OBJS)

fclean:	clean
	@rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re

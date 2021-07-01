##
## EPITECH PROJECT, 2018
## makefile
## File description:
## makefile
##

SRC_ALL		=	src/option_h.c			\
				src/file.c				\
				src/lib/my_strcmp.c		\
				src/lib/my_putstr.c		\
				src/lib/my_strlen.c		\
				src/lib/itos_base.c		\
				src/lib/list_p1.c		\
				src/lib/my_getnbr.c		\
				src/lib/my_revstr.c		\
				src/lib/my_strncpy.c	\
				src/lib/my_strncat.c	\
				src/lib/read_file.c		\
				src/lib/my_strcat.c		\
				src/lib/my_strcpy.c		\
				src/lib/my_itos.c

SRC_ANT		=	src/antman/main.c		\
				src/antman/txt/txt.c	\
				src/antman/txt/tools.c	\
				src/antman/ppm/ppm.c	\
				src/antman/ppm/utils.c

SRC_GIA		=	src/giantman/main.c		\
				src/giantman/txt/txt.c	\
				src/giantman/txt/tools.c\
				src/giantman/ppm/ppm.c

CFLAGS		=	-Iinclude#-W -Wall -Wextra

CC			=	gcc -no-pie -g

OBJ_ANT		=	$(SRC_ANT:.c=.o)

OBJ_GIA		=	$(SRC_GIA:.c=.o)

OBJ_ALL		=	$(SRC_ALL:.c=.o)

NAME_ANT	=	antman

NAME_GIA	=	giantman

all: $(NAME_ANT)

$(NAME_ANT): $(OBJ_ANT) $(OBJ_GIA) $(OBJ_ALL)
	$(CC) -o antman/$(NAME_ANT) $(OBJ_ANT) $(OBJ_ALL)
	$(CC) -o giantman/$(NAME_GIA) $(OBJ_GIA) $(OBJ_ALL)

clean:
	rm -f $(OBJ_ANT)
	rm -f $(OBJ_GIA)
	rm -f $(OBJ_ALL)
	rm -f *.o

fclean:	clean
	rm -f $(NAME_ANT)
	rm -f $(NAME_GIA)

re:	fclean all

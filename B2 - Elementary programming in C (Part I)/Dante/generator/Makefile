##
## EPITECH PROJECT, 2018
## makefile
## File description:
## makefile
##

SRC_LIB		=	my_getnbr.c			\
				my_str_isnum.c		\
				my_strcmp.c

SRC_GEN		=	first_gen.c				\
				alloc.c 				\
				generator.c				\
				end.c					\
				move.c					\
				new_way.c				\
				gen.c					\
				main.c

CC			=	gcc

RM 			= 	rm -f

DIR_GCOVR	=	gcovr/

OBJ_DIR 	= 	src
LIB_DIR 	= 	lib

OBJ_LIB		=	$(addprefix $(LIB_DIR)/, $(SRC_LIB:.c=.o))
OBJ_GEN		=	$(addprefix $(OBJ_DIR)/, $(SRC_GEN:.c=.o))

NAME		=	generator

CFLAGS		=	-W -Wall -Wextra

CPPFLAGS	=	-I./include/

all: $(NAME)

$(NAME): $(OBJ_GEN) $(OBJ_LIB)
	$(CC) -o $@ $^

tests_run: fclean
	make -C tests/

clean:
	$(RM) $(OBJ_GEN)
	$(RM) $(OBJ_LIB)

fclean:	clean
	$(RM) $(NAME)
	make -C tests/ $@

re:	fclean all

gcovr: tests_run
	mkdir -p $(DIR_GCOVR) && cd $(DIR_GCOVR); \
		gcovr --root ../ --exclude "../tests" --html --html-details --html-title $(NAME) -o $(NAME).html

.PHONY: all clean fclean tets_run re gcovr

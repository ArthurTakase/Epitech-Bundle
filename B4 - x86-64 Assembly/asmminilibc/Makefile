##
## EPITECH PROJECT, 2022
## B-ASM-400-BDX-4-1-asmminilibc-arthur.decaen [WSL: Ubuntu-20.04]
## File description:
## Makefile
##

NAME	= 	libasm.so
ASM		= 	nasm
CC		= 	ld
CFLAGS	= 	-fPIC -shared
ASFLAGS	= 	-f elf64

SRC		=	src/strlen.asm			\
			src/strchr.asm			\
			src/strrchr.asm			\
			src/memset.asm			\
			src/memcpy.asm			\
			src/strcmp.asm			\
			src/strncmp.asm			\
			src/strcasecmp.asm		\
			src/strstr.asm			\
			src/memmove.asm

T_SRC	=	tests/t_strlen.c		\
			tests/t_strchr.c		\
			tests/t_strrchr.c		\
			tests/t_memset.c		\
			tests/t_memcpy.c		\
			tests/t_strcmp.c		\
			tests/t_strncmp.c		\
			tests/t_strcasecmp.c

OBJ		= 	$(SRC:.asm=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.asm
	$(ASM) $(ASFLAGS) -o $@ $<

clean:
	rm -rf $(OBJ)
	rm -rf *.gcno
	rm -rf *.gcda
	rm -rf test
	rm -rf *.gcno *.gcda

fclean: clean
	rm -rf $(NAME)

re:	fclean all

tests_run:	re
	gcc $(T_SRC) -ldl -o test -lcriterion --coverage
	./test

.PHONY: all $(NAME) clean fclean re tests_run
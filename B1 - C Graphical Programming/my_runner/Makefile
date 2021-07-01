##
## EPITECH PROJECT, 2018
## makefile
## File description:
## makefile
##

SRC		=		src/main/main.c				\
				src/main/draw.c				\
				src/main/event.c			\
				src/main/jump.c				\
				src/main/option.c			\
				src/main/help.c				\
				src/main/game_loop.c		\
				src/init/init_back.c		\
				src/init/init_player.c		\
				src/init/init_clock.c		\
				src/init/init_sound.c		\
				src/init/init_trap.c		\
				src/init/init_score.c		\
				src/init/init_menu.c		\
				src/init/init_filtre.c		\
				src/init/init_jauge.c		\
				src/event/check_coll.c		\
				src/event/check_score.c		\
				src/event/check_jauge.c		\
				src/anime/anime.c			\
				src/anime/player.c			\
				src/anime/trap.c			\
				src/anime/cursor.c			\
				src/level/read_file.c		\
				src/level/place.c			\
				src/lib/my_putstr.c			\
				src/lib/my_strlen.c			\
				src/lib/my_strcmp.c			\
				src/lib/my_getnbr.c			\
				src/lib/my_strcat.c			\
				src/lib/my_strcpy.c			\
				src/lib/my_revstr.c			\
				src/lib/my_itos.c			\
				src/list/list_p1.c			\
				src/list/list_p2.c			\
				src/menu/level_menu.c		\
				src/menu/end_game.c			\
				src/menu/tools_menu.c		\
				src/menu/pause_menu.c		\
				src/menu/change_fps.c		\
				src/destroy/destroy_all.c	\
				src/destroy/destroy_part.c	\
				src/score/highscore.c

LDFLAGS		=	-lcsfml-graphics -lcsfml-window -l csfml-system -lcsfml-audio -lm

CFLAGS		=	-Iinclude #-W -Wall -Wextra

CC			=	gcc #-no-pie

OBJ			=	$(SRC:.c=.o)

NAME		=	my_runner

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	rm -f $(OBJ)
	rm -f *.o

fclean:	clean
	rm -f $(NAME)
	rm -f unit_tests

re:	fclean all

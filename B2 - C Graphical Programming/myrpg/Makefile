##
## EPITECH PROJECT, 2021
## B-MUL-200-BDX-2-1-mydefender-arthur.decaen
## File description:
## Makefile
##

SRC_LIB		=	lib/clonestr.c										\
				lib/my_in.c											\
				lib/my_itos.c										\
				lib/my_strcat.c										\
				lib/my_strcmp.c										\
				lib/my_strlen.c										\
				lib/my_putstr.c										\
				lib/my_revstr.c										\
				lib/my_getnbr.c										\
				lib/len_array.c										\
				lib/my_put_nbr.c									\
				lib/my_putchar.c									\
				lib/str_isnum.c

SRC_ENGINE	=	src/engine/display/anime.c							\
				src/engine/display/cursor.c							\
				src/engine/display/drawsprite.c						\
				src/engine/init/init_clock.c						\
				src/engine/init/init_sound.c						\
				src/engine/init/init_sprites.c						\
				src/engine/init/init_txt.c							\
				src/engine/init/init_window.c						\
				src/engine/init/init_player.c						\
				src/engine/init/init_player_map.c					\
				src/engine/init/init_fight.c						\
				src/engine/init/init_back.c							\
				src/engine/init/init_fade.c							\
				src/engine/init/init_menu.c							\
				src/engine/set/set_fullscreen.c						\
				src/engine/set/set_volume.c							\
				src/engine/set/set_fps.c							\
				src/engine/tools/button.c							\
				src/engine/tools/dtime.c							\
				src/engine/tools/random_float.c						\
				src/engine/tools/destroy.c							\
				src/engine/tools/usage.c							\
				src/engine/tools/my_rand.c							\
				src/engine/tools/delet_sprite.c						\
				src/engine/animation/character.c					\
				src/engine/animation/fade.c							\
				src/engine/tools/txt_from_value.c					\
				src/engine/linked_list/dlist.c						\
				src/engine/linked_list/dlist_add.c					\
				src/engine/linked_list/dlist_remove.c				\
				src/engine/particles/new_particles.c

SRC_MAP		=	src/map/buttons/init_button_simple.c				\
				src/map/save/map_save.c								\
				src/map/save/read_save/read.c						\
				src/map/init_map.c									\
				src/map/map_display.c								\
				src/map/tile_remove.c								\
				src/map/tile.c										\
				src/map/switch_map.c								\
				src/scenes/map/button_event.c						\
				src/scenes/map/event.c								\
				src/scenes/map/map_deplacement.c					\
				src/scenes/map/scene.c

SRC_INV		=	src/scenes/inventory/event.c						\
				src/scenes/inventory/scene.c						\
				src/scenes/inventory/go_to.c						\
				src/scenes/inventory/items.c

SRC_FIGHT	=	src/scenes/fight/scene.c							\
				src/scenes/fight/event/event.c						\
				src/scenes/fight/event/attack.c						\
				src/scenes/fight/event/end.c						\
				src/scenes/fight/event/player_menu.c				\
				src/scenes/fight/event/run.c						\
				src/scenes/fight/event/ennemis.c					\
				src/scenes/fight/tools.c							\
				src/scenes/fight/launch.c							\
				src/scenes/fight/draw/draw.c						\
				src/scenes/fight/draw/move.c						\
				src/scenes/fight/draw/parallax.c					\
				src/scenes/fight/infos_ennemis.c

SRC_GAME	=	src/scenes/game/event.c								\
				src/scenes/game/scene.c								\
				src/scenes/game/manage_level.c

SRC_E_FIGHT	=	src/scenes/end_fight/scene.c						\
				src/scenes/end_fight/event.c						\
				src/scenes/end_fight/anime.c

SRC_MENU	=	src/scenes/home/event.c								\
				src/scenes/home/scene.c								\
				src/scenes/home/buttons.c

SRC_PARAM	=	src/scenes/param/scene.c							\
				src/scenes/param/event.c							\
				src/scenes/param/buttons.c

SRC			=	$(SRC_LIB)											\
				$(SRC_ENGINE)										\
				$(SRC_FIGHT)										\
				$(SRC_E_FIGHT)										\
				$(SRC_MAP)											\
				$(SRC_INV)											\
				$(SRC_GAME)											\
				$(SRC_MENU)											\
				$(SRC_PARAM)										\
				src/rpg/gameloop.c									\
				src/rpg/init.c										\
				src/rpg/rpg.c

SRC_ALL		=	$(SRC)												\
				src/main.c

LDFLAGS		=	-lcsfml-graphics -lcsfml-window -l csfml-system -lcsfml-audio -lm

CFLAGS		=	-W -Wall -Wextra

CPPFLAGS	=	-Iinclude

CC			=	gcc -g -no-pie

DIR_GCOVR	=	gcovr/

OBJ			=	$(SRC_ALL:.c=.o)

NAME		=	my_rpg

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	rm -f $(OBJ)
	rm -f $(T_OBJ)
	rm -f *.gcno
	rm -f *.gcda

fclean:	clean
	rm -f $(NAME)
	rm -f unit_tests

re:	fclean all

tests_run: $(T_OBJ)
	$(CC) -o unit_tests ${SRC} -Iinclude tests/test.c --coverage -lcriterion
	./unit_tests

gcovr: tests_run
	mkdir -p $(DIR_GCOVR) && cd $(DIR_GCOVR); \
		gcovr --root ../ --exclude "../tests" --html --html-details --html-title $(NAME) -o $(NAME).html

game: all clean
	./my_rpg
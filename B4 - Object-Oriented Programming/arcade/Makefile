##
## EPITECH PROJECT, 2022
## B-OOP-400-BDX-4-1-arcade-arthur.decaen
## File description:
## Makefile
##

# -----------------------------------
#               INFOS
# -----------------------------------

# Sources
SRC_CORE		=	src/arcade.cpp					\
					src/core/Core.cpp				\
					src/core/CoreLoop.cpp			\
					src/core/Sprite.cpp				\
					src/core/Text.cpp				\
					src/games/AGame.cpp				\
					src/core/CoreHighScore.cpp

SRC_NCRUSES		=	src/libs/Ncurses.cpp
SRC_SDL2		=	src/libs/SDL2.cpp
SRC_SFML		=	src/libs/SFML.cpp

SRC_NIBBLER		=	src/games/nibbler/Nibbler.cpp	\
					src/games/AGame.cpp				\
					src/core/Sprite.cpp
SRC_SOLARFOX	=	src/games/solarfox/SolarFox.cpp	\
					src/games/solarfox/Ennemy.cpp	\
					src/games/solarfox/PiouPiou.cpp \
					src/games/AGame.cpp				\
					src/core/Sprite.cpp

# Infos
OBJ_CORE		=	$(SRC_CORE:.cpp=.o)
NAME			=	arcade

OBJ_NIBBLER		=	$(SRC_NIBBLER:.cpp=.o)
NAME_NIBBLER	=	lib/arcade_nibbler.so
OBJ_SOLARFOX	=	$(SRC_SOLARFOX:.cpp=.o)
NAME_SOLARFOX	=	lib/arcade_solarfox.so

OBJ_NCURSES		=	$(SRC_NCRUSES:.cpp=.o)
NAME_NCURSES	=	lib/arcade_ncurses.so
OBJ_SDL2		=	$(SRC_SDL2:.cpp=.o)
NAME_SDL2		=	lib/arcade_sdl2.so
OBJ_SFML		=	$(SRC_SFML:.cpp=.o)
NAME_SFML		=	lib/arcade_sfml.so

CC				=	g++

# Flags
MAKEFLAGS		+= 	--no-print-directory
SHARED_FLAGS	=	-shared -fPIC
CPPFLAGS		=	-W -Wall -Wextra -Iinclude -g -no-pie -ldl -fPIC -fno-gnu-unique
SDL_FLAGS		=	$(SHARED_FLAGS) -lSDL2 -lSDL2_ttf -lSDL2_image
SFML_FLAGS		=	$(SHARED_FLAGS) -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
NCURSES_FLAGS	=	$(SHARED_FLAGS) -lcurses

# Couleurs
NC				=	"\033[0m"
YELLOW			=	"\033[1;33m"
GREEN			=	"\033[1;32m"
RED				=	"\033[1;31m"
CYAN			=	"\033[1;36m"

# -----------------------------------
#              COMMANDES
# -----------------------------------

all: core graphicals games

# Display
core_display:
	@echo $(YELLOW)"[1/3] CORE COMPILATION ⚙️"$(NC)

games_display:
	@echo $(YELLOW)"[3/3] GAMES_COMPILATION ⚙️"$(NC)

graphicals_display:
	@echo $(YELLOW)"[2/3] LIB COMPILATION ⚙️"$(NC)

core: core_display $(NAME)

games: games_display $(NAME_NIBBLER) $(NAME_SOLARFOX)

graphicals: graphicals_display $(NAME_NCURSES) $(NAME_SDL2) $(NAME_SFML)

# Compilations
$(NAME): $(OBJ_CORE)
	@$(CC) $(OBJ_CORE) $(CPPFLAGS) -o $(NAME)

$(NAME_NCURSES): $(OBJ_NCURSES)
	@$(CC) $(OBJ_NCURSES) $(NCURSES_FLAGS) -o $(NAME_NCURSES)

$(NAME_SDL2): $(OBJ_SDL2)
	@$(CC) $(OBJ_SDL2) $(SDL_FLAGS) -o $(NAME_SDL2)

$(NAME_SFML): $(OBJ_SFML)
	@$(CC) $(OBJ_SFML) $(SFML_FLAGS) -o $(NAME_SFML)

$(NAME_NIBBLER): $(OBJ_NIBBLER)
	@$(CC) $(OBJ_NIBBLER) -o $(NAME_NIBBLER) $(SHARED_FLAGS)

$(NAME_SOLARFOX): $(OBJ_SOLARFOX)
	@$(CC) $(OBJ_SOLARFOX) -o $(NAME_SOLARFOX) $(SHARED_FLAGS)

clean:
	@rm -f $(OBJ)
	@rm -f $(OBJ_CORE)
	@rm -f $(OBJ_NIBBLER)
	@rm -f $(OBJ_SOLARFOX)
	@rm -f $(OBJ_NCURSES)
	@rm -f $(OBJ_SDL2)
	@rm -f $(OBJ_SFML)
	@rm -rf *.gcda *.gcno
	@rm -rf vgcore*
	@rm -rf test

fclean:	clean
	@rm -f $(NAME)
	@rm -f $(NAME_NIBBLER)
	@rm -f $(NAME_NCURSES)
	@rm -f $(NAME_SDL2)
	@rm -f $(NAME_SFML)
	@rm -f $(NAME_SOLARFOX)

re:	fclean all

tests-run:
	@echo $(RED)"No units tests"$(NC)

push:
	@echo $(CYAN)"[1/4] MAKE ⚒️"$(NC)
	@make fclean
	@make all
	@make fclean
	@echo $(CYAN)"[2/4] FORMAT ✍️"$(NC)
	@find . -regex '.*\.\(cpp\|hpp\|cc\|cxx\)' -exec clang-format -style=file -i {} \;
	@echo $(GREEN)"Format Done !"$(NC)
	@echo $(CYAN)"[3/4] TESTS ✏️"$(NC)
	@make tests-run
	@echo $(CYAN)"[4/4] PUSH 📤"$(NC)
	@git add .
	@git commit -m "$m"
	@git push
	@echo $(GREEN)"DONE ! ✅ "$(NC)

.PHONY: $(NAME) all clean fclean re core_display core games_display games graphicals_display graphicals push tests-run
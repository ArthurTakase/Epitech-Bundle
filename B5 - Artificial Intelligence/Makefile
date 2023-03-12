##
## EPITECH PROJECT, 2022
## B-AIA-500-BDX-5-1-gomoku-arthur.decaen
## File description:
## Makefile
##

NC				=	"\033[0m"
GREEN			=	"\033[1;32m"
RED				=	"\033[1;31m"
CYAN			=	"\033[1;36m"

NAME 			=	pbrain-gomoku-ai
MAKEFLAGS		+= 	--no-print-directory

SRC				=	src/api.py				\
					src/board.py			\
					src/game.py 			\
					src/gomoku.py			\
					src/main.py				\
					src/tree.py				\
					src/ai_min_max.py		\

all:
	@cp src/main.py $(NAME)
	@cp src/main.py $(NAME).py
	@chmod +x $(NAME)
	@chmod +x $(NAME).py

fclean:
	@rm -f $(NAME)
	@rm -f $(NAME).py
	@rm -f *.spec
	@rm -rf build
	@rm -rf dist

re: fclean all

windows:
	@echo $(CYAN)".exe for the tournament..."$(NC)
	pip install pyinstaller
	pyinstaller $(SRC) --name $(NAME).exe --onefile
	@echo $(GREEN)".exe created"$(NC)
	copy .\dist\$(NAME).exe .

windows_bis:
	@echo $(CYAN)".exe for the tournament..."$(NC)
	pip install pyinstaller
	python -m PyInstaller $(SRC) -n $(NAME).exe --onefile
	@echo $(GREEN)".exe created"$(NC)
	cp .\dist\$(NAME).exe .

windows-clean:
	@echo $(CYAN)"Cleaning .exe..."$(NC)
	rmdir /s /q build
	rmdir /s /q dist
	del .\$(NAME).exe
	del *.spec
	@echo $(GREEN)".exe cleaned"$(NC)

.PHONY: all fclean re windows windows-clean

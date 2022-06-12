##
## EPITECH PROJECT, 2022
## B-CNA-410-BDX-4-1-groundhog-arthur.decaen
## File description:
## Makefile
##

# Flags
MAKEFLAGS		+= 	--no-print-directory

# Couleurs
NC				=	"\033[0m"
GREEN			=	"\033[1;32m"
RED				=	"\033[1;31m"
CYAN			=	"\033[1;36m"

all:
	@cp src/main.py groundhog
	@chmod +x groundhog

fclean:
	@rm -f groundhog

re: fclean all

tests-run:
	pytest --cov=src tests/  
#	@echo $(RED)"No units tests"$(NC)

test:
	@echo $(CYAN)"[1/4] MAKE ⚒️"$(NC)
	@make fclean
	@make all
	@echo $(GREEN)"Compilation Done !"$(NC)
	@echo $(CYAN)"[2/4] LAUNCH 🐋"$(NC)
	@echo $(GREEN)"./groundhog 7 < examples/example_2.txt"$(NC)
	@./groundhog 7 < examples/example_2.txt
	@echo $(CYAN)"[3/4] FORMAT ✍️"$(NC)
	@black .
	@echo $(GREEN)"Format Done !"$(NC)
	@echo $(CYAN)"[4/4] TESTS ✏️"$(NC)
	@make tests-run
	@echo $(GREEN)"Vous pouvez push en toute sécurité ! ✅ "$(NC)
	@make fclean

push:
	@echo $(CYAN)"[1/5] MAKE ⚒️"$(NC)
	@make fclean
	@make all
	@echo $(GREEN)"Compilation Done !"$(NC)
	@echo $(CYAN)"[2/5] LAUNCH 🐋"$(NC)
	@./groundhog 7 < examples/example_1.txt
	@echo $(CYAN)"[3/5] FORMAT ✍️"$(NC)
	@black .
	@echo $(GREEN)"Format Done !"$(NC)
	@echo $(CYAN)"[4/5] TESTS ✏️"$(NC)
	@make tests-run
	@echo $(CYAN)"[5/5] PUSH 📤"$(NC)
	@git add .
	@git commit -m "$m"
	@git push
	@echo $(GREEN)"DONE ! ✅ "$(NC)
	@make fclean

.PHONY: all fclean re tests-run push
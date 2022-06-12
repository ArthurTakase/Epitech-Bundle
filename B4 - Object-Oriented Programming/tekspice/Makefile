##
## EPITECH PROJECT, 2022
## B-OOP-400-BDX-4-1-tekspice-arthur.decaen [WSL: Ubuntu-20.04]
## File description:
## Makefile
##

SRC			=	src/modules/C4081.cpp			\
				src/modules/C4001.cpp			\
				src/modules/C4011.cpp			\
				src/modules/C4071.cpp			\
				src/modules/C4030.cpp			\
				src/modules/C4069.cpp			\
				src/modules/Input.cpp			\
				src/modules/Output.cpp			\
				src/Gates.cpp					\
				src/AComponent.cpp				\
				src/ManagerComponent.cpp		\
				src/NanoTekSpice.cpp			\
				src/UserInterface.cpp			\
				src/Parser.cpp

SRC_ALL		=	$(SRC)							\
				src/main.cpp

TEST_SRC 	=	tests/test_C4081.cpp			\
				tests/test_C4001.cpp			\
				tests/test_C4011.cpp			\
				tests/test_C4030.cpp			\
				tests/test_C4071.cpp			\
				tests/test_C4069.cpp			\
				tests/test_Input.cpp			\
				tests/test_Output.cpp			\
				tests/test_ManagerComponent.cpp	\
				tests/test_Parser.cpp

OBJ			=	$(SRC_ALL:.cpp=.o)

CPPFLAGS	=	-W -Wall -Wextra -Iinclude -g -no-pie

NAME		=	nanotekspice

all: $(NAME)

$(NAME): $(OBJ)
	g++ -o $(NAME) $(OBJ) $(CPPFLAGS)

clean:
	rm -f $(OBJ)
	rm -rf *.gcda *.gcno
	rm -rf vgcore*
	rm -rf test

fclean:	clean
	rm -f $(NAME)

re:	fclean all

unit_tests:	fclean
	g++ -o test $(SRC) $(TEST_SRC) -lcriterion --coverage

tests_run:	unit_tests
	./test
	gcovr --exclude tests/
	rm -rf test
	rm -rf *.gcno *.gcda
	rm -rf $(OBJ)

.PHONY: $(NAME) all clean fclean re unit_tests tests_run
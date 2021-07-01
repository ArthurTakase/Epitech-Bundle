##
## EPITECH PROJECT, 2018
## makefile
## File description:
## makefile
##

all:
	make -C generator/
	make -C solver/

clean:
	make -C generator/ $@
	make -C solver/ $@

fclean:
	make -C generator/ $@
	make -C solver/ $@

re:
	make -C generator/ $@
	make -C solver/ $@

tests_run:
	make -C generator/ $@
	make -C solver/ $@

gcovr:
	make -C generator/ $@
	make -C solver/ $@

.PHONY: all clean fclean re tests_run gcovr

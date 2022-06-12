##
## EPITECH PROJECT, 2022
## B-PSU-400-BDX-4-1-nmobjdump-arthur.decaen
## File description:
## Makefile
##

all: nm objdump

nm:
	cd nm && make
	mv nm/my_nm my_nm

objdump:
	cd objdump && make
	mv objdump/my_objdump my_objdump

clean:
	cd nm && make clean
	cd objdump && make clean

fclean:	clean
	cd nm && make fclean
	cd objdump && make fclean
	rm -f my_nm
	rm -f my_objdump

re:	fclean all

.PHONY: all clean fclean re nm objdump

/*
** EPITECH PROJECT, 2022
** B-PSU-400-BDX-4-1-nmobjdump-arthur.decaen
** File description:
** check_header
*/

#include "nm.h"

int check_header(ElfW(Ehdr) *header)
{
    if (header->e_ident[EI_MAG0] != ELFMAG0 ||
        header->e_ident[EI_MAG1] != ELFMAG1 ||
        header->e_ident[EI_MAG2] != ELFMAG2 ||
        header->e_ident[EI_MAG3] != ELFMAG3 ||
        header->e_ident[EI_CLASS] != ELFCLASS64 ||
        (header->e_type != ET_EXEC
        && header->e_type != ET_REL
        && header->e_type != ET_DYN))
        return 0;
    return 1;
}

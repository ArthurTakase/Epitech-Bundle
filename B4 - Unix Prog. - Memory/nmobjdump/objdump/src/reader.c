/*
** EPITECH PROJECT, 2022
** B-PSU-400-BDX-4-1-nmobjdump-arthur.decaen
** File description:
** reader
*/

#include "objdump.h"

void read_from_file(void *data, ElfW(Shdr) *s_header, int i)
{
    unsigned int oct = 0;

    while (oct < s_header[i].sh_size) {
        if (oct % 16 == 0)
            printf("\n %04x", (unsigned int)(s_header[i].sh_addr + oct));
        if (oct % 4 == 0)
            printf(" ");
        printf("%02x", *(unsigned char *)(data + s_header[i].sh_offset + oct));
        oct++;
        if (oct % 16 == 0)
            show_value((void *)(data + s_header[i].sh_offset + oct - 16), 16);
    }
    if (oct % 16 != 0) {
        add_space(oct);
        show_value((void *)(data + s_header[i].sh_offset + oct - (oct % 16)),
            (oct % 16));
    }
}

int check_flags(ElfW(Ehdr) *header, ElfW(Shdr) *s_header)
{
    int i = -1;
    int value = 0;

    if (header->e_type == ET_EXEC)
        value |= EXEC_P;
    if (header->e_type == ET_DYN)
        value |= DYNAMIC | HAS_SYMS;
    if (header->e_phnum > 0)
        value |= D_PAGED;
    if (header->e_type == ET_REL)
        value |= HAS_RELOC;
    while (++i < header->e_shnum)
        if (s_header[i].sh_type == SHT_SYMTAB)
            value |= HAS_SYMS;
    return (value);
}

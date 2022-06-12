/*
** EPITECH PROJECT, 2022
** B-PSU-400-BDX-4-1-nmobjdump-arthur.decaen
** File description:
** get_type
*/

#include "nm.h"

char check_wv_shndx(ElfW(Sym) sym, ElfW(Shdr) *shdr)
{
    (void)shdr;
    if (ElfSt(64)(sym.st_info) == STB_WEAK) {
        if (ELF64_ST_TYPE(sym.st_info) == STT_OBJECT)
            return 'V';
        return 'W';
    }
    if (sym.st_shndx == SHN_UNDEF)
        return 'U';
    if (sym.st_shndx == SHN_ABS)
        return 'A';
    if (sym.st_shndx == SHN_COMMON)
        return 'C';
    return 0;
}

char check_shtype(ElfW(Sym) sym, ElfW(Shdr) *shdr)
{
    if (shdr[sym.st_shndx].sh_type == SHT_NOBITS &&
        shdr[sym.st_shndx].sh_flags == (SHF_ALLOC | SHF_WRITE))
        return 'B';
    if (shdr[sym.st_shndx].sh_type == SHT_PROGBITS &&
        (shdr[sym.st_shndx].sh_flags == SHF_ALLOC ||
        shdr[sym.st_shndx].sh_flags == (SHF_MERGE | SHF_ALLOC)))
        return 'R';
    if ((shdr[sym.st_shndx].sh_type == SHT_PROGBITS &&
        shdr[sym.st_shndx].sh_flags == (SHF_ALLOC | SHF_WRITE)) ||
        shdr[sym.st_shndx].sh_type == SHT_DYNAMIC)
        return 'D';
    if ((shdr[sym.st_shndx].sh_type == SHT_PROGBITS &&
        shdr[sym.st_shndx].sh_flags == (SHF_ALLOC | SHF_EXECINSTR)) ||
        shdr[sym.st_shndx].sh_type == SHT_INIT_ARRAY ||
        shdr[sym.st_shndx].sh_type == SHT_FINI_ARRAY)
        return 'T';
    return 0;
}

void check_special(char *symb, char *type)
{
    char *cases[] = {"__do_global_dtors_aux_fini_array_entry",
                    "__frame_dummy_init_array_entry",
                    "__init_array_end",
                    "__init_array_start",
                    NULL};

    for (int i = 0; cases[i]; i++)
        if (!strcmp(symb, cases[i]))
            *type = 'd';
}

void check_lowcase(ElfW(Sym) sym, char *type)
{
    if ((ElfSt(64)(sym.st_info) == STB_LOCAL && *type != 0) ||
        ((*type == 'W' || *type == 'V') && sym.st_shndx == SHN_UNDEF))
        *type += 32;
}

char get_type(ElfW(Sym) sym, ElfW(Shdr) *shdr, char *symb)
{
    char type = ElfSt(64)(sym.st_info);
    char (*funct[3])(ElfW(Sym), ElfW(Shdr) *) = {&check_wv_shndx,
                                                &check_shtype};

    type = (type == STB_GNU_UNIQUE) ? 'u' : 0;
    for (int i = 0; i < 2 && type == 0; i++)
        type = funct[i](sym, shdr);
    check_lowcase(sym, &type);
    check_special(symb, &type);
    return type;
}

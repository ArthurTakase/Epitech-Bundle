/*
** EPITECH PROJECT, 2022
** B-PSU-400-BDX-4-1-nmobjdump-arthur.decaen
** File description:
** main
*/

#include "nm.h"

void get_symtab_strtab(t_nm *nm)
{
    char *str = (char *)(nm->data + nm->shdr[nm->ehdr->e_shstrndx].sh_offset);

    for (int i = 0; i < nm->ehdr->e_shnum; i++) {
        if (nm->shdr[i].sh_size) {
            if (strcmp(&str[nm->shdr[i].sh_name], ".symtab") == 0)
                nm->symtab = (ElfW(Shdr) *)&nm->shdr[i];
            if (strcmp(&str[nm->shdr[i].sh_name], ".strtab") == 0)
                nm->strtab = (ElfW(Shdr) *)&nm->shdr[i];
        }
    }
}

int my_nm(char *filename)
{
    int fd;
    t_nm nm;

    if ((fd = open(filename, O_RDONLY)) == -1)
        return printf("nm: '%s': No such file\n", filename);
    nm.data = mmap(NULL, lseek(fd, 0, SEEK_END), PROT_READ, MAP_SHARED, fd, 0);
    if (nm.data == MAP_FAILED)
        return printf("nm: '%s': No such file\n", filename);
    nm.ehdr = (ElfW(Ehdr) *)nm.data;
    if (!check_header(nm.ehdr))
        return printf("nm: '%s': File format not recognized\n", filename);
    nm.shdr = (ElfW(Shdr) *)(nm.data + nm.ehdr->e_shoff);
    get_symtab_strtab(&nm);
    get_symb(&nm);
    print_symb(&nm);
    free_symb(&nm);
    return 0;
}

int main(int argc, char **argv)
{
    int i = 1;

    if (argc == 1)
        my_nm("a.out");
    if (argc > 1)
        for (; argv[i]; i++)
            my_nm(argv[i]);
    return 0;
}

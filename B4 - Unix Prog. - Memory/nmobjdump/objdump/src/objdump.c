/*
** EPITECH PROJECT, 2022
** B-PSU-400-BDX-4-1-nmobjdump-arthur.decaen
** File description:
** main
*/

#include "objdump.h"

int print(char *str, char *file)
{
    printf("objdump: '%s': %s\n", file, str);
    return 0;
}

int objdump(char *filename)
{
    t_obj ob;
    int fd;

    if ((fd = open(filename, O_RDONLY)) == -1)
        return print("No such file", filename);
    ob.data = mmap(NULL, lseek(fd, 0, SEEK_END), PROT_READ, MAP_SHARED, fd, 0);
    if (ob.data == MAP_FAILED)
        return print("No such file", filename);
    ob.ehdr = (ElfW(Ehdr) *)ob.data;
    if (check_header(ob.ehdr) == 0)
        return print("File format not recognized", filename);
    ob.shdr = (ElfW(Shdr) *)(ob.data + ob.ehdr->e_shoff);
    ob.strtab = (char *)(ob.data + ob.shdr[ob.ehdr->e_shstrndx].sh_offset);
    show_format(filename, &ob);
    show_sections(&ob);
    return 0;
}

int main(int argc, char **argv)
{
    int i = 1;

    if (argc == 1)
        return objdump("a.out");
    if (argc > 1)
        for (; argv[i]; i++)
            objdump(argv[i]);
    return 0;
}

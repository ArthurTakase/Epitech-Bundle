/*
** EPITECH PROJECT, 2022
** B-PSU-400-BDX-4-1-nmobjdump-arthur.decaen
** File description:
** printer
*/

#include "objdump.h"

void show_flags(ElfW(Ehdr) *header, ElfW(Shdr) *s_header)
{
    char *all_flags = malloc(sizeof(char) * 100);

    if (header->e_type == ET_EXEC)
        strcat(all_flags, "EXEC_P, ");
    if (header->e_type == ET_REL)
        strcat(all_flags, "HAS_RELOC, ");
    for (int i = 0; i < header->e_shnum; i++)
        if (s_header[i].sh_type == SHT_SYMTAB)
            strcat(all_flags, "HAS_SYMS, ");
    if (header->e_type == ET_DYN)
        strcat(all_flags, "DYNAMIC, ");
    if (header->e_phnum > 0)
        strcat(all_flags, "D_PAGED, ");
    all_flags[strlen(all_flags) - 2] = '\0';
    printf("%s", all_flags);
    free(all_flags);
}

void show_value(void *data, unsigned int size)
{
    char *str;
    unsigned int i = 0;

    printf("  ");
    for (; i < size; i++) {
        str = data + i;
        if (check_char(*str) == 1)
            printf("%c", *str);
        else
            printf(".");
    }
    for (; i < 16; i++)
        printf(" ");
}

void show_format(char *filename, t_obj *obj)
{
    printf("\n%s:     file format elf%d-x86-64\n", filename, SYSTEM);
    printf("architecture: %s, flags 0x%08x:\n",
        obj->ehdr->e_machine == EM_X86_64 ? "i386:x86-64" : "unknown",
        check_flags(obj->ehdr, obj->shdr));
    show_flags(obj->ehdr, obj->shdr);
    printf("\n");
    printf("start address 0x%016x\n", (unsigned int)obj->ehdr->e_entry);
}

void show_sections(t_obj *obj)
{
    for (int i = 0; i < obj->ehdr->e_shnum; i++) {
        if (strlen(&obj->strtab[obj->shdr[i].sh_name]) != 0 &&
            strcmp(&obj->strtab[obj->shdr[i].sh_name], ".strtab") &&
            strcmp(&obj->strtab[obj->shdr[i].sh_name], ".symtab") &&
            strcmp(&obj->strtab[obj->shdr[i].sh_name], ".shstrtab") &&
            strcmp(&obj->strtab[obj->shdr[i].sh_name], ".bss")) {
            printf("\nContents of section %s:",
                    &obj->strtab[obj->shdr[i].sh_name]);
            read_from_file(obj->data, obj->shdr, i);
        }
    }
    printf("\n");
}

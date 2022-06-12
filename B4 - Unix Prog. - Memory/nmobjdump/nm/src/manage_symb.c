/*
** EPITECH PROJECT, 2022
** B-PSU-400-BDX-4-1-nmobjdump-arthur.decaen
** File description:
** manage_symb
*/

#include "nm.h"

void print_symb(t_nm *nm)
{
    for (int i = 0; nm->symb_tab[i]; i++)
        if (strcmp(nm->symb_tab[i]->symb, "") &&
            !strstr(nm->symb_tab[i]->symb, ".c")) {
                printf("%s ", nm->symb_tab[i]->nbr);
                printf("%c ", nm->symb_tab[i]->type);
                printf("%s\n", nm->symb_tab[i]->symb);
            }
}

void free_symb(t_nm *nm)
{
    for (int i = 0; nm->symb_tab[i]; i++)
        free(nm->symb_tab[i]);
    free(nm->symb_tab);
}

static int compare_symb(const void *a, const void *b)
{
    t_symb *first = * (t_symb **)a;
    t_symb *second = * (t_symb **)b;
    char *un = first->symb;
    char *deux = second->symb;

    if (un[0] == '_')
        un++;
    if (un[0] == '_')
        un++;
    if (deux[0] == '_')
        deux++;
    if (deux[0] == '_')
        deux++;
    if (!strcmp(un, deux))
        return strcasecmp(first->symb, second->symb);
    return strcasecmp(un, deux);
}

void get_symb(t_nm *nm)
{
    char *str = (char *)(nm->data + nm->strtab->sh_offset);
    size_t size = nm->symtab->sh_size / sizeof(ElfW(Sym));
    char *symb;

    nm->sym = (ElfW(Sym) *)(nm->data + nm->symtab->sh_offset);
    nm->symb_tab = malloc(sizeof(t_symb *) * (size + 1));
    for (size_t i = 0; i < size; i++) {
        symb = str + nm->sym[i].st_name;
        nm->symb_tab[i] = malloc(sizeof(t_symb));
        nm->symb_tab[i]->symb = symb;
        nm->symb_tab[i]->type = get_type(nm->sym[i], nm->shdr, symb);
        nm->symb_tab[i]->nbr = "0000000000000000";
        if (nm->symb_tab[i]->type == 'U' || nm->symb_tab[i]->type == 'w')
            nm->symb_tab[i]->nbr = "                ";
    }
    nm->symb_tab[size] = NULL;
    qsort(nm->symb_tab, size, sizeof(t_symb *), compare_symb);
}

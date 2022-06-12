/*
** EPITECH PROJECT, 2022
** B-PSU-400-BDX-4-1-nmobjdump-arthur.decaen
** File description:
** nm
*/

#ifndef NM_H_
    #define NM_H_

    #if defined(__LP64__)
        #define ElfW(type) Elf64_ ## type
        #define ElfSt(type) ELF ## type ## _ST_BIND
        #define SYSTEM 64
    #else
        #define ElfW(type) Elf32_ ## type
        #define ElfSt(type) ELF ## type ## _ST_BIND
        #define SYSTEM 32
    #endif

    #include <elf.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <fcntl.h>
    #include <sys/mman.h>
    #include <string.h>

typedef struct s_symb {
    char *symb;
    char type;
    char *nbr;
} t_symb;

typedef struct s_nm {
    ElfW(Ehdr) *ehdr;
    ElfW(Shdr) *shdr;
    ElfW(Shdr) *strtab;
    ElfW(Shdr) *symtab;
    ElfW(Sym) *sym;
    void *data;
    t_symb **symb_tab;
} t_nm;

int check_header(ElfW(Ehdr) *header);
char get_type(ElfW(Sym) sym, ElfW(Shdr) *shdr, char *symb);
void print_symb(t_nm *nm);
void free_symb(t_nm *nm);
void get_symb(t_nm *nm);

#endif

/*
** EPITECH PROJECT, 2022
** B-PSU-400-BDX-4-1-nmobjdump-arthur.decaen
** File description:
** objdump
*/

#ifndef __OBJDUMP_H__
    #define __OBJDUMP_H__

    #include <elf.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <fcntl.h>
    #include <sys/mman.h>
    #include <string.h>
    #include "flags.h"

    #if defined(__LP64__)
        #define ElfW(type) Elf64_##type
        #define SYSTEM 64
    #else
        #define ElfW(type) Elf32_##type
        #define SYSTEM 32
    #endif

typedef struct s_obj {
    ElfW(Ehdr) * ehdr;
    ElfW(Shdr) * shdr;
    void *data;
    char *strtab;
} t_obj;

void show_sections(t_obj *);
void read_from_file(void *, ElfW(Shdr) *, int);
void add_space(int);
void show_value(void *, unsigned int);
void show_format(char *filename, t_obj *obj);
void show_flags(ElfW(Ehdr) *, ElfW(Shdr) *);
int check_flags(ElfW(Ehdr) *, ElfW(Shdr) *);
int check_char(char);
int check_header(ElfW(Ehdr) *);

#endif

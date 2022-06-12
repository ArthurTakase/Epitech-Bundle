/*
** EPITECH PROJECT, 2022
** B-ASM-400-BDX-4-1-asmminilibc-arthur.decaen [WSL: Ubuntu-20.04]
** File description:
** t_strlen
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <dlfcn.h>
#include <string.h>

Test(strlen_hello, succeed)
{
    char *str = malloc(sizeof(char) * 5 + 1);
    void *shared_lib = dlopen("./libasm.so", RTLD_LAZY);
    size_t (*my_strlen)(const char *);
    *(void **)(&my_strlen) = dlsym(shared_lib, "strlen");
    
    strcpy(str, "hello");
    
    cr_expect_eq(strlen(str), 5);
    free(str);
    dlclose(shared_lib);
}

Test(strlen_null, succeed)
{
    void *shared_lib = dlopen("./libasm.so", RTLD_LAZY);
    size_t (*my_strlen)(const char *);
    *(void **)(&my_strlen) = dlsym(shared_lib, "strlen");
    
    cr_expect_eq(strlen(""), NULL);
    dlclose(shared_lib);
}
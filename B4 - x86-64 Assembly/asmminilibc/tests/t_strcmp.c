/*
** EPITECH PROJECT, 2022
** B-ASM-400-BDX-4-1-asmminilibc-arthur.decaen [WSL: Ubuntu-20.04]
** File description:
** t_strcmp
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <dlfcn.h>
#include <string.h>

Test(strcmp_hello_coucou, got_5)
{
    char *str = malloc(sizeof(char) * 5 + 1);
    void *shared_lib = dlopen("./libasm.so", RTLD_LAZY);
    int (*my_strcmp)(const char *, const char *);
    *(void **)(&my_strcmp) = dlsym(shared_lib, "strcmp");
    
    strcpy(str, "hello");
    
    cr_expect_eq(my_strcmp(str, "coucou"), 5);
    free(str);
    dlclose(shared_lib);
}

Test(strcmp_hello_hello, got_0)
{
    char *str = malloc(sizeof(char) * 5 + 1);
    void *shared_lib = dlopen("./libasm.so", RTLD_LAZY);
    int (*my_strcmp)(const char *, const char *);
    *(void **)(&my_strcmp) = dlsym(shared_lib, "strcmp");
    
    strcpy(str, "hello");
    
    cr_expect_eq(my_strcmp(str, "hello"), 0);
    free(str);
    dlclose(shared_lib);
}
/*
** EPITECH PROJECT, 2022
** B-ASM-400-BDX-4-1-asmminilibc-arthur.decaen [WSL: Ubuntu-20.04]
** File description:
** t_strncmp
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <dlfcn.h>
#include <string.h>

Test(strncmp_hello_coucou_3, got_5)
{
    char *str = malloc(sizeof(char) * 5 + 1);
    void *shared_lib = dlopen("./libasm.so", RTLD_LAZY);
    int (*my_strncmp)(const char *, const char *, size_t);
    *(void **)(&my_strncmp) = dlsym(shared_lib, "strncmp");
    
    strcpy(str, "hello");
    
    cr_expect_eq(my_strncmp(str, "coucou", 3), 5);
    free(str);
    dlclose(shared_lib);
}

Test(strncmp_hello_hello_3, got_0)
{
    char *str = malloc(sizeof(char) * 5 + 1);
    void *shared_lib = dlopen("./libasm.so", RTLD_LAZY);
    int (*my_strncmp)(const char *, const char *, size_t);
    *(void **)(&my_strncmp) = dlsym(shared_lib, "strncmp");
    
    strcpy(str, "hello");
    
    cr_expect_eq(my_strncmp(str, str, 3), 0);
    free(str);
    dlclose(shared_lib);
}

Test(strncmp_hello_hella_3, got_0)
{
    char *str = malloc(sizeof(char) * 5 + 1);
    void *shared_lib = dlopen("./libasm.so", RTLD_LAZY);
    int (*my_strncmp)(const char *, const char *, size_t);
    *(void **)(&my_strncmp) = dlsym(shared_lib, "strncmp");
    
    strcpy(str, "hello");
    
    cr_expect_eq(my_strncmp(str, "hella", 3), 0);
    free(str);
    dlclose(shared_lib);
}
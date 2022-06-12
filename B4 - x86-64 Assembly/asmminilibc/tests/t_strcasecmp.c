/*
** EPITECH PROJECT, 2022
** B-ASM-400-BDX-4-1-asmminilibc-arthur.decaen [WSL: Ubuntu-20.04]
** File description:
** t_strcasecmp
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <dlfcn.h>
#include <string.h>

Test(strcasecmp_hello_coucou, got_5)
{
    char *str = malloc(sizeof(char) * 5 + 1);
    void *shared_lib = dlopen("./libasm.so", RTLD_LAZY);
    int (*my_strcasecmp)(const char *, const char *);
    *(void **)(&my_strcasecmp) = dlsym(shared_lib, "strcasecmp");
    
    strcpy(str, "hello");
    
    cr_expect_eq(my_strcasecmp(str, "coucou"), 5);
    free(str);
    dlclose(shared_lib);
}

Test(strcasecmp_hello_Hello, got_0)
{
    char *str = malloc(sizeof(char) * 5 + 1);
    void *shared_lib = dlopen("./libasm.so", RTLD_LAZY);
    int (*my_strcasecmp)(const char *, const char *);
    *(void **)(&my_strcasecmp) = dlsym(shared_lib, "strcasecmp");
    
    strcpy(str, "hello");
    
    cr_expect_eq(my_strcasecmp(str, "Hello"), 0);
    free(str);
    dlclose(shared_lib);
}

Test(strcasecmp_heLlo_HElLO, got_0)
{
    char *str = malloc(sizeof(char) * 5 + 1);
    void *shared_lib = dlopen("./libasm.so", RTLD_LAZY);
    int (*my_strcasecmp)(const char *, const char *);
    *(void **)(&my_strcasecmp) = dlsym(shared_lib, "strcasecmp");
    
    strcpy(str, "heLlo");
    
    cr_expect_eq(my_strcasecmp(str, "HElLO"), 0);
    free(str);
    dlclose(shared_lib);
}

Test(strcasecmp_heLlo_HELLa, got_11)
{
    char *str = malloc(sizeof(char) * 5 + 1);
    void *shared_lib = dlopen("./libasm.so", RTLD_LAZY);
    int (*my_strcasecmp)(const char *, const char *);
    *(void **)(&my_strcasecmp) = dlsym(shared_lib, "strcasecmp");
    
    strcpy(str, "heLlo");
    
    cr_expect_eq(my_strcasecmp(str, "HELLa"), 14);
    free(str);
    dlclose(shared_lib);
}
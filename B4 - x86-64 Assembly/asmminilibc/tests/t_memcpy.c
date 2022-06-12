/*
** EPITECH PROJECT, 2022
** B-ASM-400-BDX-4-1-asmminilibc-arthur.decaen [WSL: Ubuntu-20.04]
** File description:
** t_memcpy
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <dlfcn.h>
#include <string.h>

Test(memcpy_hello_2, succeed)
{
    char *str = malloc(sizeof(char) * 5 + 1);
    void *shared_lib = dlopen("./libasm.so", RTLD_LAZY);
    char *(*my_memcpy)(void *, const void *, size_t);
    *(void **)(&my_memcpy) = dlsym(shared_lib, "memcpy");

    strcpy(str, "hello");

    cr_expect_str_eq(my_memcpy(str, "coucou", 2), "collo");
    free(str);
    dlclose(shared_lib);
}

Test(memcpy_hello_0, succeed)
{
    char *str = malloc(sizeof(char) * 5 + 1);
    void *shared_lib = dlopen("./libasm.so", RTLD_LAZY);
    char *(*my_memcpy)(void *, const void *, size_t);
    *(void **)(&my_memcpy) = dlsym(shared_lib, "memcpy");

    strcpy(str, "hello");

    cr_expect_str_eq(my_memcpy(str, "coucou", 0), "hello");
    free(str);
    dlclose(shared_lib);
}

Test(memcpy_hello_8, succeed)
{
    char *str = malloc(sizeof(char) * 5 + 1);
    void *shared_lib = dlopen("./libasm.so", RTLD_LAZY);
    char *(*my_memcpy)(void *, const void *, size_t);
    *(void **)(&my_memcpy) = dlsym(shared_lib, "memcpy");

    strcpy(str, "hello");
    
    cr_expect_str_eq(my_memcpy(str, "coucou", 8), "coucou");
    free(str);
    dlclose(shared_lib);
}

Test(memcpy_null_2, succeed)
{
    char *str = malloc(sizeof(char) * 5 + 1);
    void *shared_lib = dlopen("./libasm.so", RTLD_LAZY);
    char *(*my_memcpy)(void *, const void *, size_t);
    *(void **)(&my_memcpy) = dlsym(shared_lib, "memcpy");

    cr_expect_str_eq(my_memcpy(str, "coucou", 2), "co");
    dlclose(shared_lib);
}
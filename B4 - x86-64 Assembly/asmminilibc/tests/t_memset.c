/*
** EPITECH PROJECT, 2022
** B-ASM-400-BDX-4-1-asmminilibc-arthur.decaen [WSL: Ubuntu-20.04]
** File description:
** t_memset
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <dlfcn.h>
#include <string.h>

Test(memset_hello_2, succeed)
{
    char *str = malloc(sizeof(char) * 5 + 1);
    void *shared_lib = dlopen("./libasm.so", RTLD_LAZY);
    char *(*my_memset)(const void *, int, size_t);
    *(void **)(&my_memset) = dlsym(shared_lib, "memset");
    
    strcpy(str, "hello");
    
    cr_expect_str_eq(my_memset(str, 'A', 2), "AAllo");
    free(str);
    dlclose(shared_lib);
}

Test(memset_hello_0, succeed)
{
    char *str = malloc(sizeof(char) * 5 + 1);
    void *shared_lib = dlopen("./libasm.so", RTLD_LAZY);
    char *(*my_memset)(const void *, int, size_t);
    *(void **)(&my_memset) = dlsym(shared_lib, "memset");
    
    strcpy(str, "hello");
    
    cr_expect_str_eq(my_memset(str, 'A', 0), "hello");
    free(str);
    dlclose(shared_lib);
}

Test(memset_hello_8, succeed)
{
    char *str = malloc(sizeof(char) * 5 + 1);
    void *shared_lib = dlopen("./libasm.so", RTLD_LAZY);
    char *(*my_memset)(const void *, int, size_t);
    *(void **)(&my_memset) = dlsym(shared_lib, "memset");
    
    strcpy(str, "hello");
    
    cr_expect_str_eq(my_memset(str, 'A', 8), "AAAAAAAA");
    free(str);
    dlclose(shared_lib);
}
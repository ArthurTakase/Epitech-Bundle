/*
** EPITECH PROJECT, 2022
** B-ASM-400-BDX-4-1-asmminilibc-arthur.decaen [WSL: Ubuntu-20.04]
** File description:
** t_strchr
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <dlfcn.h>
#include <string.h>

Test(strchr_hello, succeed)
{
    char *str = malloc(sizeof(char) * 5 + 1);
    void *shared_lib = dlopen("./libasm.so", RTLD_LAZY);
    char *(*my_strchr)(const char *, const char);
    *(void **)(&my_strchr) = dlsym(shared_lib, "strchr");
    
    strcpy(str, "hello");
    
    cr_expect_str_eq(my_strchr(str, 'l'), "llo");
    free(str);
    dlclose(shared_lib);
}

Test(strchr_null, succeed)
{
    void *shared_lib = dlopen("./libasm.so", RTLD_LAZY);
    char *(*my_strchr)(const char *, const char);
    *(void **)(&my_strchr) = dlsym(shared_lib, "strchr");
    
    cr_expect_eq(my_strchr("", 'l'), NULL);
    dlclose(shared_lib);
}

Test(strchr_null_null, succeed)
{
    char *str = malloc(sizeof(char) * 5 + 1);
    void *shared_lib = dlopen("./libasm.so", RTLD_LAZY);
    char *(*my_strchr)(const char *, const char);
    *(void **)(&my_strchr) = dlsym(shared_lib, "strchr");
    
    strcpy(str, "hello");
    
    cr_expect_eq(my_strchr(str, '_'), NULL);
    dlclose(shared_lib);
    free(str);
}

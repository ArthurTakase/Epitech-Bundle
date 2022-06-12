/*
** EPITECH PROJECT, 2022
** B-ASM-400-BDX-4-1-asmminilibc-arthur.decaen [WSL: Ubuntu-20.04]
** File description:
** t_strrchr
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <dlfcn.h>
#include <string.h>

Test(strrchr_hello, succeed)
{
    char *str = malloc(sizeof(char) * 5 + 1);
    void *shared_lib = dlopen("./libasm.so", RTLD_LAZY);
    char *(*my_strrchr)(const char *, const char);
    *(void **)(&my_strrchr) = dlsym(shared_lib, "strrchr");
    
    strcpy(str, "hello");
    
    cr_expect_str_eq(my_strrchr(str, 'l'), "lo");
    free(str);
    dlclose(shared_lib);
}

Test(strrchr_null, succeed)
{
    void *shared_lib = dlopen("./libasm.so", RTLD_LAZY);
    char *(*my_strrchr)(const char *, const char);
    *(void **)(&my_strrchr) = dlsym(shared_lib, "strrchr");
    
    cr_expect_eq(strrchr("", 'l'), NULL);
    dlclose(shared_lib);
}

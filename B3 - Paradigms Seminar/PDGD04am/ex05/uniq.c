/*
** EPITECH PROJECT, 2022
** B-PDG-300-BDX-3-1-PDGD04am-arthur.decaen
** File description:
** uniq
*/

#include <stdio.h>

size_t uniq_int_array(int *array, size_t nmemb)
{
    int temp[nmemb];
    int j = 0;

    if (nmemb == 0 || (int)nmemb == 1)
        return nmemb;
    for (int i = 0; i < (int)nmemb - 1; i++)
        if (array[i] != array[i + 1])
            temp[j++] = array[i];
    temp[j++] = array[nmemb - 1];
    for (int i = 0; i < j; i++)
        array[i] = temp[i];
    return (size_t)j;
}

size_t uniq_array(void *array, size_t nmemb, size_t size,
                int (*compar) (const void *, const void *))
{
    return nmemb;
}

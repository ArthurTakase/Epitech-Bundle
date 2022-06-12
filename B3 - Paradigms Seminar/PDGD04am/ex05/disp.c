/*
** EPITECH PROJECT, 2022
** B-PDG-300-BDX-3-1-PDGD04am-arthur.decaen
** File description:
** disp
*/

#include <stdio.h>
#include <string.h>

void disp_int_array(const int *array, size_t nmemb)
{
    for (size_t i = 0; i < nmemb; i++)
        printf("%d, ", array[i]);
    printf("\n");
}

void disp_array(const void *array, size_t nmemb, size_t size,
                void (*print) (const void *))
{
    for (size_t i = 0; i < nmemb; i++)
        (*print)(array + i * size);
}

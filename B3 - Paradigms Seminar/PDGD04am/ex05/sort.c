/*
** EPITECH PROJECT, 2022
** B-PDG-300-BDX-3-1-PDGD04am-arthur.decaen
** File description:
** sort
*/

#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort_int_array(int *array , size_t nmemb)
{
    for (int i = 0; i < (int)nmemb - 1; i++) {
        for (int j = 0; j < (int)nmemb - i - 1; j++) {
            if (array[j] > array[j + 1])
                swap(&array[j], &array[j + 1]);
        }
    }
}

void sort_array(void *array, size_t nmemb, size_t size,
                int (*compar) (const void *, const void *))
{
    for (int i = 0; i < (int)nmemb - 1; i++) {
        for (int j = 1; j < (int)nmemb - i - 1; j++) {
            if ((*compar)(array + j * size, array + (j + 1) * size) > 0)
                swap(array + j * size, array + (j + 1) * size);
        }
    }
}

/*
** EPITECH PROJECT, 2020
** my_sort_int_array
** File description:
** sort in from an integer array
*/

int my_swap(int *a, int *b);

void my_sort_int_array2(int *array, int size, int j)
{
    if (array[j] > array[j+1])
        my_swap(&array[j], &array[j+1]);
}

void my_sort_int_array(int *array, int size)
{
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size-i-1; j++)
            my_sort_int_array2(array, size, j);
    }
}

/*
** EPITECH PROJECT, 2020
** compare tab
** File description:
** compare tab
*/

#include "include/my.h"

int abs(int n);

// Compares each value of a letter with that of another language.
//Returns the sum of the difference of each value.
int compare(int *our_lang, int *ref)
{
    int temp = 0;

    for (int j = 0; j < 26; j++) {
        if (our_lang[j] != 0)
            temp += (abs(our_lang[j] - ref[j]));
    }
    return temp;
}

// Launches the compare() function with the English values
int compare_eng(int *our_lang)
{
    int ref_eng[26] = {816, 149, 278, 425, 1270, 222, 201, 609, 696,
        15, 77, 402, 240, 674, 750, 192, 9, 598,
        632, 905, 275, 97, 236, 15, 197, 7};
    return compare(our_lang, ref_eng);
}

// Launches the compare() function with the French values
int compare_fr(int *our_lang)
{
    int ref_fr[26] = {763, 90, 326, 366, 1471, 106, 86, 73, 752,
        61, 7, 545, 296, 709, 579, 252, 136, 669,
        794, 224, 631, 183, 4, 42, 12, 32};
    return compare(our_lang, ref_fr);
}

// Launches the compare() function with the German values
int compare_all(int *our_lang)
{
    int ref_all[26] = {651, 188, 273, 507, 1639, 165, 300, 457, 655,
        26, 141, 343, 253, 977, 259, 67, 1, 700,
        727, 615, 416, 84, 192, 3, 3, 113};
    return compare(our_lang, ref_all);
}

// Launches the compare() function with the Spanish values
int compare_esp(int *our_lang)
{
    int ref_esp[26] = {1152, 221, 401, 501, 1218, 69, 176, 70, 624,
        49, 1, 496, 315, 671, 868, 251, 87, 687,
        797, 463, 292, 113, 1, 21, 100, 46};
    return compare(our_lang, ref_esp);
}

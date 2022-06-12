/*
** EPITECH PROJECT, 2022
** B-PDG-300-BDX-3-1-PDGD04am-arthur.decaen
** File description:
** mul_div
*/

void mul_div_long(int a, int b, int *mul, int *div)
{
    *mul = a * b;
    *div = (b == 0) ? 42 : a / b;
}

void mul_div_short(int *a, int *b)
{
    int mul = (*a) * (*b);
    int div = ((*b) == 0) ? 42 : (*a) / (*b);

    *a = mul;
    *b = div;
}

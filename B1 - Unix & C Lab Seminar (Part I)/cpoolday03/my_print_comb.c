/*
** EPITECH PROJECT, 2020
** my_print_comb
** File description:
** show numbers witch some tweaks
*/

int my_putchar(char c);

// Display the number
int print_number(int a, int b, int c)
{
    my_putchar(a);
    my_putchar(b);
    my_putchar(c);
    if (!(a == 55 && b == 56 && c == 57)) {
        my_putchar(',');
        my_putchar(' ');
    } else
        my_putchar('\n');
    return 0;
}

// Check number value
int check_number(int a, int b, int c)
{
    if (a != b && a != c && b != c)
        if (a < b && b < c)
            print_number(a, b, c);
    return 0;
}

//FOR THE NORME !
int my_print_comb_part2(int a, int b, int c)
{
    while (b != 56){
        b++;
        while (c != 57) {
            c++;
            check_number(a, b, c);
        }
        c = 47;
    }
    b = 47;
    return 0;
}

// Main Function
int my_print_comb(void)
{
    int a = 47;
    int b = a + 1;
    int c = b + 1;

    while (a != 55) {
        a++;
        my_print_comb_part2(a, b, c);
    }
    return 0;
}

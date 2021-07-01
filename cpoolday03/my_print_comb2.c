/*
** EPITECH PROJECT, 2020
** My_Print_Comb2
** File description:
** display two two sorting number
*/

int my_putchar(char c);

// Convert 42 to 4 and 2
int convert_number(int number)
{
    int digit2 = number % 10;
    int digit1 = (number - digit2) / 10;
    my_putchar(digit1 + 48);
    my_putchar(digit2 + 48);
    return 0;
}

// Print Numbers
int print_numberv2(int a, int b)
{
    convert_number(a);
    my_putchar(' ');
    convert_number(b);
    if (!(a == 98 && b == 99)) {
        my_putchar(',');
        my_putchar(' ');
    }
    return 0;
}

int check_numberv2(int a, int b)
{
    if (a != b){
        if (a < b){
            print_numberv2(a, b);
        }
    }
    return 0;
}

//Main Function
int my_print_comb2(void)
{
    int a = -1;
    int b = -1;

    while (a != 99){
        a++;
        while (b != 99){
            b++;
            check_numberv2(a, b);
        }
        b = 0;
    }
    return 0;
}

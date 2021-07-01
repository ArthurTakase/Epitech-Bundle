/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** my.h
*/

#define line(void) my_putchar('\n')
#define MIN(X, Y) ((X) < (Y) ? (X) : (Y))
#define MAX(X, Y) ((X) < (Y) ? (Y) : (X))

int my_compute_power_rec(int nb, int p);
int my_compute_square_root (int nb);
int my_find_prime_sup (int nb);
int my_getnbr(char const *str);
int my_getnbr_base(char *str, char *base);
int my_isneg(int n);
int my_is_prime(int nb);
void my_putchar(char c);
void my_put_nbr(int nb);
int my_putnbr_base(int nbr, char const *base);
int my_putstr(char const *str);
char *my_revstr(char *str);
int my_showmem(char const *str, int size);
int my_showstr(char *str);
void my_sort_int_array(int *array, int size);
char *my_strcapitalize(char *str);
char *my_strcat(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
char *my_strcpy(char *dest, char const *src);
int my_str_isalpha(char const *str);
int my_str_islower(char const *str);
int my_str_isnum(char const *str);
int my_str_isprintable(char const *str);
int my_str_isupper(char const *str);
int my_strlen(char const *str);
char *my_strlowcase(char *str);
char *my_strncat(char *dest, char const *src, int nb);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strstr(char *str, char const *to_find);
char *my_strupcase(char *str);
void my_swap(int *a, int *b);
int my_show_word_array(char * const *tab);
char *my_strdup(char const *src);
char **my_str_to_word_array(char const *str);
int len(char const *str);
int len2(char const *str);
void modif_str(char *str, int i);
int len_str_alpha(char const *str);
int len_str_lower(char const *str);
int len_str_num(char const *str);
int len_str_printable(char const *str);
int len_str_upper(char const *str);
int count_words(char const *str);
int is_alphanum(char str);
void my_sort_int_array2(int *array, int size);
char *my_strstr2(char *str, char const *to_find, int i, int j);
int my_in(char want, char *source);
int my_abs(int n);
int my_howmanyin(char c, char *str);

/*
** EPITECH PROJECT, 2021
** Test Error Handling
** File description:
** test_error_handling
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my_redirect.h"
#include "my_errors.h"

Test(error_handling, valid)
{
    int ac = 2;
    char *av[2] = {"./solver", "mazes/10x10_maze_perfect"};
    char *result = error_handling(ac, (const char **)av);
    char *expect = "*X***X***X\n\
*X*X*X*X*X\n\
***X*X*X*X\n\
XXXX*X*X*X\n\
***X*X*X*X\n\
*XXX*X*X*X\n\
*****X*X*X\n\
*XXX*X*X*X\n\
***X***X*X\n\
XXXXXXXX**";

    cr_assert_str_eq(result, expect);
}

Test(error_handling, file_invalid, .init = redirect_all_std)
{
    int ac = 2;
    char *av[2] = {"./solver", "I_do_not_exist"};

    error_handling(ac, (const char **)av);
    cr_assert_stderr_eq_str("ERROR: Incorrect file.\n\n\
You could try ./solver -h\n");
}

Test(error_handling, empty_file_invalid, .init = redirect_all_std)
{
    int ac = 2;
    char *av[2] = {"./solver", "mazes/empty_file"};
    error_handling(ac, (const char **)av);

    cr_assert_stderr_eq_str("ERROR: Incorrect file.\n\n\
You could try ./solver -h\n");
}

Test(error_handling, bad_width_invalid, .init = redirect_all_std)
{
    int ac = 2;
    char *av[2] = {"./solver", "mazes/bad_width"};
    error_handling(ac, (const char **)av);

    cr_assert_stderr_eq_str("ERROR: The maze isn't a rectangle \
(neigher a square)\n\nYou could try ./solver -h\n");
}

Test(error_handling, bad_width_last_line_invalid, .init = redirect_all_std)
{
    int ac = 2;
    char *av[2] = {"./solver", "mazes/bad_width_last_line"};
    error_handling(ac, (const char **)av);

    cr_assert_stderr_eq_str("ERROR: The maze isn't a rectangle \
(neigher a square)\n\nYou could try ./solver -h\n");
}

Test(error_handling, char_invalid, .init = redirect_all_std)
{
    int ac = 2;
    char *av[2] = {"./solver", "mazes/char_invalid"};
    error_handling(ac, (const char **)av);

    cr_assert_stderr_eq_str("ERROR: Invalid character\n\n\
You could try ./solver -h\n");
}

Test(error_handling, usage_invalid, .init = redirect_all_std)
{
    int ac = 2;
    char *av[2] = {"./solver", "-h"};
    char *result = error_handling(ac, (const char **)av);

    cr_assert_null(result);
}

Test(error_handling, ac_invalid, .init = redirect_all_std)
{
    int ac = 3;
    char *av[3] = {"./solver", "wesh", "canne a peche"};
    error_handling(ac, (const char **)av);

    cr_assert_stderr_eq_str("ERROR: Incorrect number of arguments.\n\n\
You could try ./solver -h\n");
}

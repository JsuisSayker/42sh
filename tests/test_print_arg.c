/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** test_print_arg
*/

#include "mysh.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_print_arg(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(print_arg, basic_true, .init = redirect_print_arg) {
    mysh_t mysh_need;
    char **env = spliter("PATH=/usr/bin:/bin|toto=tata", "|");
    cr_assert_eq(print_arg(env), 0);
    cr_assert_stdout_eq_str("PATH=/usr/bin:/bin\ntoto=tata\n");
    free_map(env);
}

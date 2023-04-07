/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** test_add_equal
*/

#include "mysh.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(add_equal, basic) {
    char *str = add_equal("toto");
    cr_assert_str_eq(str, "toto=");
    free(str);
}

Test(add_equal, rigor) {
    char *str = add_equal(NULL);
    cr_assert_eq(str, NULL);
}
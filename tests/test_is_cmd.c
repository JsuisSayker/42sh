/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** test_is_cmd
*/

#include "mysh.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(is_cmd, basic_test){
    char *s1 = "cd";
    char *s2 = "cd";
    int return_value = is_cmd(s1, s2);
    cr_assert_eq(return_value, 0);
}

Test(is_cmd, basic_test_2){
    char *s1 = "cd toto";
    char *s2 = "cd";
    int return_value = is_cmd(s1, s2);
    cr_assert_eq(return_value, 0);
}

Test(is_cmd, s2_not_in_s1){
    char *s1 = "cdtoto";
    char s2[] = "cd=";
    int return_value = is_cmd(s1, s2);
    cr_assert_eq(return_value, 1);
}

Test(is_cmd, NULL_s1){
    char s2[] = "cd";
    int return_value = is_cmd(NULL, s2);
    cr_assert_eq(return_value, -1);
}

Test(is_cmd, NULL_s2){
    char *s1 = "cd toto";
    int return_value = is_cmd(s1, NULL);
    cr_assert_eq(return_value, -1);
}

Test(is_cmd, NULL_all){
    int return_value = is_cmd(NULL, NULL);
    cr_assert_eq(return_value, -1);
}

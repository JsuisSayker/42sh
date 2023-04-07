/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** test_str_contain_char
*/

#include "mysh.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(str_contain_char, basic_test_true){
    cr_assert_eq(str_contain_char("abcdefghijklmnopqrstuvwxyz", 'c'), 1);
    cr_assert_eq(str_contain_char("c", 'c'), 1);
    cr_assert_eq(str_contain_char("abdefghijklmnopqrstuvwxyzc", 'c'), 1);
    cr_assert_eq(str_contain_char("cabdefghijklmnopqrstuvwxyz", 'c'), 1);
    cr_assert_eq(str_contain_char("cabdefghijkcazerfenioeaecazuhufahc", 'c'), 1);
}

Test(str_contain_char, basic_test_false){
    cr_assert_eq(str_contain_char("abdefghijklmnopqrstuvwxyz", 'c'), 0);
    cr_assert_eq(str_contain_char("z", 'c'), 0);
    cr_assert_eq(str_contain_char("abdefghijklmnopqrstuvwxyzz", 'c'), 0);
    cr_assert_eq(str_contain_char("zabdefghijklmnopqrstuvwxyz", 'c'), 0);
    cr_assert_eq(str_contain_char("zaazertyuiolkjhgb", 'c'), 0);
}

Test(str_contain_char, NULL_str){
    cr_assert_eq(str_contain_char(NULL, 'c'), -1);
}

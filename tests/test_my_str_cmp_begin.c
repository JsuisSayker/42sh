/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** test_my_str_cmp_begin
*/

#include "mysh.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(my_str_cmp_begin, basic_test){
    char *s1 = "PATH=/usr/bin:/bin|toto=tata";
    char *s2 = "PATH=";
    int return_value = my_str_cmp_begin(s1, s2);
    cr_assert_eq(return_value, 0);
}

Test(my_str_cmp_begin, basic_test_2){
    char *s1 = "PATH=";
    char *s2 = "PATH=/usr/bin:/bin|toto=tata";
    int return_value = my_str_cmp_begin(s1, s2);
    cr_assert_eq(return_value, 0);
}

Test(my_str_cmp_begin, s2_not_in_s1){
    char *s1 = "PATH=/usr/bin:/bin|toto=tata";
    char s2[] = "USER=";
    int return_value = my_str_cmp_begin(s1, s2);
    cr_assert_eq(return_value, 1);
}

Test(my_str_cmp_begin, NULL_s1){
    char s2[] = "USER=";
    int return_value = my_str_cmp_begin(NULL, s2);
    cr_assert_eq(return_value, -1);
}

Test(my_str_cmp_begin, NULL_s2){
    char *s1 = "PATH=/usr/bin:/bin|toto=tata";
    int return_value = my_str_cmp_begin(s1, NULL);
    cr_assert_eq(return_value, -1);
}

Test(my_str_cmp_begin, NULL_all){
    int return_value = my_str_cmp_begin(NULL, NULL);
    cr_assert_eq(return_value, -1);
}

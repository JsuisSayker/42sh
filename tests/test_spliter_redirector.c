/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** test_spliter_redirector
*/

#include "mysh.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(spliter_redirector, basic_test){
    char *redirector[] = { ";", "|", ">>", ">", "<<", "<", NULL };
    char *str = generate_malloc_str_from_str("ls -la|grep Makefile");
    char **split_str = spliter_redirector(str, redirector);
    free(str);
    cr_assert_str_eq(split_str[0], "ls -la");
    cr_assert_str_eq(split_str[1], "|");
    cr_assert_str_eq(split_str[2], "grep Makefile");
    cr_assert_eq(split_str[3], NULL);
    free_spliter(split_str, redirector);
}

Test(spliter_redirector, redirector_not_in_str){
    char *redirector[] = { ";", "|", ">>", ">", "<<", "<", NULL };
    char *str = generate_malloc_str_from_str("ls -la grep Makefile");
    char **split_str = spliter_redirector(str, redirector);
    free(str);
    cr_assert_str_eq(split_str[0], "ls -la grep Makefile");
    cr_assert_eq(split_str[1], NULL);
    free_map(split_str);
}

Test(spliter_redirector, NULL_str){
    char *redirector[] = { ";", "|", ">>", ">", "<<", "<", NULL };
    char **split_str = spliter_redirector(NULL, redirector);
    cr_assert_eq(split_str, NULL);
}

Test(spliter_redirector, empty_str){
    char *redirector[] = { ";", "|", ">>", ">", "<<", "<", NULL };
    char **split_str = spliter_redirector("", redirector);
    cr_assert_eq(split_str, NULL);
}

Test(spliter_redirector, NULL_redirector){
    char *str = generate_malloc_str_from_str("ls -la|grep Makefile");
    char **split_str = spliter_redirector(str, NULL);
    free(str);
    cr_assert_eq(split_str, NULL);
}

Test(spliter_redirector, NULL_first_redirector){
    char *redirector[] = { NULL, ";", NULL };
    char *str = generate_malloc_str_from_str("ls -la|grep Makefile");
    char **split_str = spliter_redirector(str, redirector);
    free(str);
    cr_assert_eq(split_str, NULL);
}
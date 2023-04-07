/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** test_switch_var_env
*/

#include "mysh.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(switch_var_env, basic_test){
    char **env = spliter("PATH=/usr/bin:/bin|toto=tata", "|");
    char value_env[] = "PATH=";
    int return_value = switch_var_env(env, value_env, "/home");
    free_map(env);
    cr_assert_eq(return_value, 0);
}

Test(switch_var_env, var_not_in_env){
    char **env = spliter("PATH=/usr/bin:/bin|toto=tata", "|");
    char value_env[] = "USER=";
    int return_value = switch_var_env(env, value_env, "/home");
    free_map(env);
    cr_assert_eq(return_value, 1);
}

Test(switch_var_env, NULL_env){
    char value_env[] = "USER=";
    int return_value = switch_var_env(NULL, NULL, "/home");
    cr_assert_eq(return_value, -1);
}

Test(switch_var_env, NULL_var_value){
    char **env = spliter("PATH=/usr/bin:/bin|toto=tata", "|");
    int return_value = switch_var_env(env, NULL, "/home");
    free_map(env);
    cr_assert_eq(return_value, -1);
}

Test(switch_var_env, NULL_str){
    char **env = spliter("PATH=/usr/bin:/bin|toto=tata", "|");
    char value_env[] = "USER=";
    int return_value = switch_var_env(env, value_env, NULL);
    free_map(env);
    cr_assert_eq(return_value, -1);
}
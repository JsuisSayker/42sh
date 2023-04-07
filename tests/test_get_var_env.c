/*
** EPITECH PROJECT, 2023
** new_project_folder_file
** File description:
** test
*/

#include "mysh.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(get_var_env, basic_test){
    char *env[] = {"PATH=/usr/bin:/bin", NULL};
    char *path = get_var_env(env, "PATH=");
    cr_assert_str_eq(path, &(env[0][5]));
}

Test(get_var_env, test_no_in_env){
    char *env[] = {"USER=Tom", "toto=ttii", NULL};
    char *path = get_var_env(env, "PATH=");
    cr_assert_eq(path, NULL);
}

Test(get_var_env, NULL_env){
    char *path = get_var_env(NULL, "PATH=");
    cr_assert_eq(path, NULL);
}

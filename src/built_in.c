/*
** EPITECH PROJECT, 2023
** built_in
** File description:
** built in commands
*/

#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <stdio.h>
#include "minishell.h"

int built_in(char ***env, char *buf_size, int *built_in_value,
int *returned_value)
{
    if (good_exit_case((*env), buf_size) == 0)
        return OK;
    bad_exit_case(buf_size, built_in_value);
    if (my_strncmp("cd", buf_size, 2) == 0) {
        cd_commands((*env), buf_size);
        (*built_in_value) = 1;
    }
    if (my_strncmp("env", buf_size, 3) == 0 && buf_size[3] == '\0') {
        env_built_in((*env));
        (*built_in_value) = 1;
    }
    if (my_strncmp("setenv", buf_size, 6) == 0) {
        (*returned_value) = setenv_built_in(env, buf_size);
        (*built_in_value) = 1;
    }
    if (my_strncmp("unsetenv", buf_size, 8) == 0) {
        unsetenv_built_in(env, buf_size);
        (*built_in_value) = 1;
    }
    return KO;
}

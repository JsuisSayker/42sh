/*
** EPITECH PROJECT, 2023
** setenv
** File description:
** setenv functions
*/

#include <stddef.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include "minishell.h"

static int bad_input_case(char **command)
{
    if (my_str_is_alphanum(command[1]) == false) {
        write(2, "setenv: Variable name must contain alphanumeric \
characters.\n", 61);
        free_command(command);
        return KO;
    }
    return OK;
}

static void which_case(char ***env, char **command)
{
    if (path_finder((*env), command[1]) == NULL && command[1] != NULL &&
    command[2] == NULL)
        set_alone_var(&(*env), command);
    if (path_finder((*env), command[1]) != NULL && command[1] != NULL &&
    command[2] != NULL)
        change_var_in_env(env, command);
    if (path_finder((*env), command[1]) == NULL && command[1] != NULL &&
    command[2] != NULL)
        set_var_and_value(env, command);
    if (path_finder((*env), command[1]) != NULL && command[1] != NULL &&
    command[2] == NULL)
        change_var_in_env(env, command);
}

int setenv_built_in(char ***env, char *buf_size)
{
    char **command = my_str_to_word_array(buf_size, "-/.=0123456789");
    if (command[1] == NULL) {
        env_built_in((*env));
        free_command(command);
        return OK;
    }
    if (bad_input_case(command) == 84)
        return 1;
    which_case(env, command);
    free_command(command);
    return OK;
}

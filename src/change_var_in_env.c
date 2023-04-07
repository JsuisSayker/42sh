/*
** EPITECH PROJECT, 2023
** change var in env value
** File description:
** change variable value in my env
*/

#include "minishell.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

void change_var_in_env(char ***env, char **command)
{
    char *command_with_eq_in_env = setup_command_with_eq(command);
    char *new_value_in_env = "";
    if (command[1] != NULL && command[2] != NULL)
        new_value_in_env = command[2];
    int len_new_str = my_strlen(command_with_eq_in_env) +
    my_strlen(new_value_in_env);
    char *new_complete_str = setup_new_complete_str(len_new_str,
    command_with_eq_in_env, new_value_in_env);
    change_the_value_in_env(env, len_new_str, new_complete_str,
    command_with_eq_in_env);
    free(command_with_eq_in_env);
    free(new_complete_str);
}

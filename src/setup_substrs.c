/*
** EPITECH PROJECT, 2023
** setup substrs
** File description:
** setup substrs
*/

#include <stdlib.h>
#include "minishell.h"

char *setup_command_with_eq(char **command)
{
    char *command_with_eq_in_env = malloc(sizeof(char) *
    (my_strlen(command[1]) + 2));
    command_with_eq_in_env[0] = '\0';
    my_strcat(command_with_eq_in_env, command[1]);
    my_strcat(command_with_eq_in_env, "=");
    return command_with_eq_in_env;
}

char *setup_new_complete_str(int len_new_str, char *command_with_eq_in_env,
char *new_value_in_env)
{
    char *new_complete_str = malloc(sizeof(char) * (len_new_str + 1));
    new_complete_str[0] = '\0';
    my_strcat(new_complete_str, command_with_eq_in_env);
    my_strcat(new_complete_str, new_value_in_env);
    return new_complete_str;
}

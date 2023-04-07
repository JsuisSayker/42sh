/*
** EPITECH PROJECT, 2023
** set var and value
** File description:
** set var and value for the setenv
*/

#include <stddef.h>
#include <stdlib.h>
#include "minishell.h"

void set_var_and_value(char ***env, char **command)
{
    char *command_with_eq_in_env = malloc(sizeof(char) *
    (my_strlen(command[1]) + 3));
    command_with_eq_in_env[0] = '\0';
    my_strcat(command_with_eq_in_env, command[1]);
    my_strcat(command_with_eq_in_env, "=");
    char **new_env_cpy = malloc(sizeof(char *) *
    (count_line_in_env((*env)) + 2));
    int i = 0;
    for (i = 0; (*env)[i] != NULL; i += 1) {
        new_env_cpy[i] = (*env)[i];
    }
    free((*env));
    new_env_cpy[i] = malloc(sizeof(char) *
    (my_strlen(command_with_eq_in_env) + my_strlen(command[2]) + 1));
    new_env_cpy[i][0] = '\0';
    my_strcat(new_env_cpy[i], command_with_eq_in_env);
    my_strcat(new_env_cpy[i], command[2]);
    new_env_cpy[i + 1] = NULL;
    (*env) = new_env_cpy;
    free(command_with_eq_in_env);
}

/*
** EPITECH PROJECT, 2023
** change the value in env
** File description:
** change the value in env when we use setenv
*/

#include <stddef.h>
#include <stdlib.h>
#include "minishell.h"

static void change_line_in_env(char ***env, char *new_complete_str,
int len_new_str, int i)
{
    free((*env)[i]);
    (*env)[i] = malloc(sizeof(char) * (len_new_str + 1));
    (*env)[i][len_new_str] = '\0';
    for (int j = 0; j < len_new_str; j += 1) {
        (*env)[i][j] = new_complete_str[j];
    }
}

void change_the_value_in_env(char ***env, int len_new_str,
char *new_complete_str, char *command_with_eq_in_env)
{
    for (int i = 0;(*env)[i] != NULL; i += 1) {
        if (my_strncmp(command_with_eq_in_env, (*env)[i] ,
        (my_strlen(command_with_eq_in_env))) == 0) {
            change_line_in_env(env, new_complete_str, len_new_str, i);
        }
    }
}

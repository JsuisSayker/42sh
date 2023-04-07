/*
** EPITECH PROJECT, 2023
** free line from env
** File description:
** a side function for unsetenv
*/

#include <stddef.h>
#include <stdlib.h>
#include "minishell.h"

void free_line_from_env(char ***env, char *command_eq, int *j)
{
    if (unset_cmp((*env)[(*j)], command_eq, my_strlen(command_eq)) == 0) {
        free((*env)[(*j)]);
        for (; (*env)[(*j) + 1] != NULL; (*j) += 1) {
            (*env)[(*j)] = (*env)[(*j) + 1];
        }
        (*env)[(*j)] = NULL;
    }
}

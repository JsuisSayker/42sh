/*
** EPITECH PROJECT, 2023
** path finder
** File description:
** a path finder for the built in command
*/

#include <stddef.h>
#include <stdio.h>
#include "minishell.h"

char *path_finder(char **env, char *str)
{
    int count = 0;
    while (env[count] != NULL) {
        if (is_sbustr_in_str(env[count], str) == 0) {
            return &(env[count][my_strlen(str)]);
        }
        count += 1;
    }
    return NULL;
}

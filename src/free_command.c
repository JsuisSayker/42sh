/*
** EPITECH PROJECT, 2023
** free_command
** File description:
** free command for the built in
*/

#include <stddef.h>
#include <stdlib.h>
#include "minishell.h"

void free_command(char **command)
{
    for (int i = 0; command[i] != NULL; i += 1)
        free(command[i]);
    free(command);
}

void free_tab(int **command)
{
    for (int i = 0; command[i] != NULL; i += 1)
        free(command[i]);
    free(command);
}

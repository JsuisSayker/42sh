/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** free_command_split
*/

#include "mysh.h"

int free_command_split(char ***command_split)
{
    for (int i = 0; command_split[i] != NULL; i += 1) {
        if (is_str_redirector(command_split[i][0]) == OK) {
            free_map(command_split[i]);
        } else {
            free(command_split[i][0]);
            free(command_split[i]);
        }
    }
    free(command_split);
    return OK;
}

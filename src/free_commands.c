/*
** EPITECH PROJECT, 2023
** free commands
** File description:
** free_commands
*/

#include <stddef.h>
#include <stdlib.h>

void free_commands(char **command_with_args, char **possible_path, char
*buf_size, char **env)
{
    for (int i = 0; command_with_args[i] != NULL; i += 1) {
        free(command_with_args[i]);
    }
    free(command_with_args);
    for (int i = 0; possible_path[i] != NULL; i += 1) {
        free(possible_path[i]);
    }
    for (int i = 0; env[i] != NULL; i += 1) {
        free(env[i]);
    }
    free(env);
    free(possible_path);
    free(buf_size);
}

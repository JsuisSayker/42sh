/*
** EPITECH PROJECT, 2023
** env_built_in
** File description:
** env built in command
*/

#include <stddef.h>
#include <unistd.h>
#include "minishell.h"

int env_built_in(char **env)
{
    for (int i = 0; env[i] != NULL; i += 1) {
        write(1, env[i], my_strlen(env[i]));
        write(1, "\n", 1);
    }
    return OK;
}

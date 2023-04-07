/*
** EPITECH PROJECT, 2023
** env_cpy
** File description:
** do a copy of my env, that permit me to midify it
*/

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "minishell.h"

char **env_cpy(char **env)
{
    int nb_line_in_env = count_line_in_env(env);
    char **env_copy = malloc(sizeof(char *) * (nb_line_in_env + 1));
    for (int i = 0; env[i] != NULL; i += 1) {
        env_copy[i] = malloc(sizeof(char) * (my_strlen(env[i]) + 1));
        for (int j = 0; env[i][j] != '\0'; j += 1) {
            env_copy[i][j] = env[i][j];
        }
        env_copy[i][my_strlen(env[i])] = '\0';
    }
    env_copy[nb_line_in_env] = NULL;
    return env_copy;
}

/*
** EPITECH PROJECT, 2023
** B-PSU-200-BDX-2-1-minishell1-tom.mendy
** File description:
** copy_env
*/

#include "mysh.h"

char **copy_env(char **env)
{
    char **new_env = NULL;
    if (env == NULL)
        return NULL;
    new_env = malloc(sizeof(char *) *(my_map_len(env) + 1));
    if (new_env == NULL)
        return NULL;
    int i = 0;
    for (; env[i] != NULL; i += 1){
        int j = 0;
        new_env[i] = malloc(sizeof(char) * (my_str_len(env[i]) + 1));
        for (; env[i][j] != '\0'; j += 1){
            new_env[i][j] = env[i][j];
        }
        new_env[i][j] = '\0';
    }
    new_env[i] = NULL;
    return new_env;
}

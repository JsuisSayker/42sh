/*
** EPITECH PROJECT, 2023
** Minishell1
** File description:
** take_env
*/

#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>

#include "macro.h"
#include "proto_lib.h"

static char *go_to_variable(char **env, char *str)
{
    int len_str = 0;
    if (env == NULL || str == NULL)
        return NULL;
    if ((len_str = my_strlen(str)) == KO)
        return NULL;
    for (int y = 0; env[y] != NULL; y += 1){
        if (my_strncmp(str, env[y], 5) == 0)
            return &env[y][len_str];
    }
    return NULL;
}

char *take_in_env(char **env, char *str)
{
    if (env == NULL)
        return NULL;
    char *path = go_to_variable(env, str);
    if (path == NULL)
        return NULL;
    return path;
}

char **take_path(char **env, char *str)
{
    if (env == NULL)
        return NULL;
    char *path = go_to_variable(env, str);
    if (path == NULL)
        return NULL;
    char **tab = my_splitstr(path, ':');
    if (tab == NULL)
        return NULL;
    return tab;
}

static char **malloc_tab(char **env)
{
    int count_word = 0;
    char **tab = NULL;
    for (int i = 0; env[i] != NULL; i += 1)
        count_word += 1;
    tab = malloc(sizeof(char *) * (count_word + 1));
    if (tab == NULL)
        return NULL;
    tab[count_word] = NULL;
    return tab;
}

char **take_env(char **env)
{
    if (env == NULL)
        return NULL;
    char **tab = malloc_tab(env);
    if (tab == NULL)
        return NULL;
    int y = 0;
    for (y = 0; env[y] != NULL; y += 1){
        tab[y] = my_strcpy(env[y]);
    }
    tab[y] = NULL;
    return tab;
}

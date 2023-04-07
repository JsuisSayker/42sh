/*
** EPITECH PROJECT, 2023
** B-PSU-200-BDX-2-1-minishell1-tom.mendy
** File description:
** unsetenv_function
*/

#include "mysh.h"

void when_str_is_find(char **env, int j)
{
    free(env[j]);
    if (env[j + 1] == NULL)
        env[j] = NULL;
    else {
        env[j] = malloc(sizeof(char) * (my_str_len(env[j + 1]) + 1));
        env[j][0] = '\0';
        my_str_cat(env[j], env[j + 1]);
    }
}

int remove_str_from_env(char **env, char *str)
{
    int find = 0;
    for (int j = 0; env[j] != NULL; j += 1) {
        if (my_str_cmp_begin(env[j], str) == OK)
            find = 1;
        if (find == 1) {
            when_str_is_find(env, j);
        }
    }
    return 0;
}

int unsetenv_function(char ***env, char **str_split)
{
    if ((*env) == NULL)
        return OK;
    if (str_split[1] == NULL) {
        write(2, "unsetenv: Too few arguments.\n", 30);
        return OK;
    }
    for (int i = 1; str_split[i] != NULL; i += 1) {
        char *str = add_equal(str_split[i]);
        remove_str_from_env((*env), str);
        free(str);
    }
    return OK;
}

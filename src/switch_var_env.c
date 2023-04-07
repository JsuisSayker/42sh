/*
** EPITECH PROJECT, 2023
** B-PSU-200-BDX-2-1-minishell1-tom.mendy
** File description:
** switch_var_env
*/

#include "mysh.h"

int switch_var_env(char **env, char *var, char *str)
{
    if (env == NULL || var == NULL || str == NULL)
        return -1;
    for (int i = 0; env[i] != NULL; i += 1){
        if (my_str_cmp_begin(env[i], var) == OK){
            free(env[i]);
            env[i] = malloc(sizeof(char) * (my_str_len(var) + my_str_len(str)
            + 1));
            env[i][0] = '\0';
            my_str_cat(env[i], var);
            my_str_cat(env[i], str);
            return 0;
        }
    }
    return 1;
}

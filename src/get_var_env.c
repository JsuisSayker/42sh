/*
** EPITECH PROJECT, 2023
** B-PSU-200-BDX-2-1-minishell1-tom.mendy
** File description:
** get_patch
*/

#include "mysh.h"

char * get_var_env(char **env, char * str)
{
    if (env == NULL)
        return NULL;
    for (int i = 0; env[i] != NULL; i += 1){
        if (my_str_cmp_begin(env[i], str) == OK){
            char *return_str = malloc(sizeof(char) *
            (my_str_len(&(env[i][my_str_len(str)])) + 1));
            return_str[0] = '\0';
            my_str_cat(return_str, &(env[i][my_str_len(str)]));
            return return_str;
        }
    }
    return NULL;
}

/*
** EPITECH PROJECT, 2023
** B-PSU-200-BDX-2-1-minishell1-tom.mendy
** File description:
** add_home_to_directory
*/

#include "mysh.h"

char *add_home_to_directory(char *str, char **env)
{
    char *home = get_var_env(env, "HOME=");
    if (str == NULL) {
        return home;
    } else {
        char *path_with_home = malloc(sizeof(char) * (my_str_len(home) +
            my_str_len(str) - 1 + 1));
        path_with_home[0] = '\0';
        my_str_cat(path_with_home, home);
        my_str_cat(path_with_home, &(str[1]));
        free(home);
        return path_with_home;
    }
}

/*
** EPITECH PROJECT, 2023
** B-PSU-200-BDX-2-1-minishell1-tom.mendy
** File description:
** add_cmd_to_path
*/

#include "mysh.h"

int add_cmd_to_path(char **path_array, char *cmd)
{
    if (path_array == NULL || cmd == NULL)
        return KO;
    int path_array_len = 0;
    for (int i = 0; path_array[i] != NULL; i += 1) {
        path_array_len = my_str_len(path_array[i]);
        char *save = malloc(sizeof(char) * (path_array_len + 1));
        for (int j = 0; j != path_array_len; j += 1) {
            save[j] = path_array[i][j];
        }
        save[path_array_len] = '\0';
        free(path_array[i]);
        path_array[i] = malloc(sizeof(char) * (path_array_len +
            my_str_len(cmd) + 1 + 1));
        path_array[i][0] = '\0';
        my_str_cat(path_array[i], save);
        my_str_cat(path_array[i], "/");
        my_str_cat(path_array[i], cmd);
        free(save);
    }
    return 0;
}

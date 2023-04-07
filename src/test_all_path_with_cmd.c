/*
** EPITECH PROJECT, 2023
** test_all_path_with_cmd
** File description:
** test_all_path_with_cmd
*/

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include "minishell.h"

void test_all_path_with_cmd(char **command_with_args, char ** possible_path,
char *buf_size, char **env)
{
    for (int i = 0; possible_path[i] != NULL && (buf_size[0] != '.' &&
    buf_size[1] != '/'); i += 1) {
        char *save_str_path = malloc(sizeof(char) *
        (my_strlen(possible_path[i]) + 1));
        for (int j = 0; possible_path[i][j]; j += 1) {
            save_str_path[j] = possible_path[i][j];
        }
        save_str_path[my_strlen(possible_path[i])] = '\0';
        free(possible_path[i]);
        possible_path[i] = malloc(sizeof(char) *
        (my_strlen(save_str_path) + 2 + (my_strlen(buf_size))));
        possible_path[i][0] = '\0';
        my_strcat(possible_path[i], save_str_path);
        my_strcat(possible_path[i], "/");
        my_strcat(possible_path[i], command_with_args[0]);
        execve(possible_path[i], command_with_args, env);
        free(save_str_path);
    }
}

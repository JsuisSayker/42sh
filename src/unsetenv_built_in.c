/*
** EPITECH PROJECT, 2023
** unsetenv built in
** File description:
** unsetenv built in
*/

#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#include "minishell.h"

void unsetenv_built_in(char ***env, char *buf_size)
{
    char **args = my_str_to_word_array(buf_size, "-/._0123456789");
    if (few_args_case(args) == 84)
        return;
    for (int i = 1; args[i] != NULL; i += 1) {
        char *command_eq = malloc(sizeof(char) * (my_strlen(args[i]) + 2));
        unset_command(command_eq, args, i);
        if (path_finder((*env), command_eq) == NULL) {
            free(command_eq);
            free_command(args);
            return;
        }
        for (int j = 0; (*env)[j] != NULL; j += 1) {
            free_line_from_env(env, command_eq, &j);
        }
        free(command_eq);
    }
    free_command(args);
}

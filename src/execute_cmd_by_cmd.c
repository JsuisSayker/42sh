/*
** EPITECH PROJECT, 2023
** execute cmd  by cmd
** File description:
** execute_cmd_by_cmd
*/

#include "minishell.h"

void execute_cmd_by_cmd(char **env, char **new_formated_str,
int *returned_value)
{
    for (int i = 0; i < my_array_length(new_formated_str); i += 1) {
        exec_command_and_binaries(new_formated_str[i], env,
        &(*returned_value));
    }
}

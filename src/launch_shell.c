/*
** EPITECH PROJECT, 2023
** launch my shell
** File description:
** launch_shell
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "minishell.h"
#include <sys/wait.h>
#include <sys/stat.h>

int is_str_null(char **new_formated_str, int *returned_value, char *buf_size)
{
    if (new_formated_str == NULL)
        return true;
    if (count_pipes(buf_size) >= 1) {
        write(2, "Invalid null command.\n", 23);
        (*returned_value) = 1;
        return true;
    }
    if (is_spaces_or_tabs(new_formated_str[0]) == true)
        return true;
    if (my_array_length(new_formated_str) == 1 &&
    (new_formated_str[0][0] == '|' && new_formated_str[0][1] == '\0')) {
        write(2, "Invalid null command.\n", 23);
        (*returned_value) = 1;
        return true;
    }
    return false;
}

int launch_shell(char **env)
{
    char *buf_size = NULL;
    size_t line_buf_size = 0;
    int returned_value = 0;
    while (1) {
        int built_in_value = 0;
        if (is_fifo() == false)
            write(1, "$> ", 3);
        if (getline(&buf_size, &line_buf_size, stdin) == -1)
            return returned_value;
        buf_size[my_strlen(buf_size) - 1] = '\0';
        char **new_formated_str = spliter_by_options(buf_size, ";");
        if (is_str_null(new_formated_str, &returned_value, buf_size) == true)
            continue;
        if (built_in(&env, buf_size, &built_in_value, &returned_value) == 0)
            return returned_value;
        if (built_in_value == 0)
            execute_cmd_by_cmd(env, new_formated_str, &returned_value);
        free_command(new_formated_str);
    }
    return OK;
}

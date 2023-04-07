/*
** EPITECH PROJECT, 2023
** exit cases
** File description:
** different exit cases
*/

#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include "minishell.h"

char *clean_str(char *str)
{
    int count = 0;
    for (int i = 0; my_char_isalpha(str[i]) == false; i += 1) {
        count += 1;
    }
    char *new_str = malloc(sizeof(char) * ((my_strlen(str) - count) + 1));
    new_str[(my_strlen(str) - count)] = '\0';
    int second_count = 0;
    for (int i = count; str[i] != '\0'; i += 1) {
        new_str[second_count] = str[i];
        second_count += 1;
    }
    return new_str;
}

int is_void(char *str)
{
    int count = 0;
    for (int i = 0; my_char_isalpha(str[i]) == false; i += 1) {
        count += 1;
    }
    for (int i = count; my_char_isalpha(str[i]) == true; i += 1) {
        count += 1;
    }
    for (int i = count; str[i] != '\0'; i += 1) {
        if (my_char_isalpha(str[i]) == true)
            return false;
    }
    return true;
}

int good_exit_case(char **env, char *buf_size)
{
    char *new_buffer = clean_str(buf_size);
    if (my_strcmp("exit", new_buffer) == 0 && is_void(new_buffer) == true) {
        write(1, new_buffer, my_strlen(new_buffer));
        write(1, "\n", 1);
        free(buf_size);
        free(new_buffer);
        free_command(env);
        return OK;
    }
    return KO;
}

void bad_exit_case(char *buf_size, int *built_in_value)
{
    char *new_buffer = clean_str(buf_size);
    if (my_strcmp("exit", new_buffer) == 0 && (new_buffer[4] == ' ')) {
        write(2, new_buffer, 4);
        write(2, ": Expression Sytax.\n", 21);
        (*built_in_value) = 1;
    }
}

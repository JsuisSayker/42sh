/*
** EPITECH PROJECT, 2023
** count line in env
** File description:
** count line in env
*/

#include <stddef.h>

int count_line_in_env(char **env)
{
    int count = 0;
    for (int i = 0; env[i] != NULL; i += 1) {
        count += 1;
    }
    return count;
}

/*
** EPITECH PROJECT, 2023
** is_spaces_or_tabs
** File description:
** if the all the str equal of spaces or tabs
*/

#include <stdbool.h>

int is_spaces_or_tabs(const char *str)
{
    for (int i = 0; str[i] != '\0'; i += 1) {
        if (str[i] == ' ' || str[i] == '\t') {
        } else
            return false;
    }
    return true;
}

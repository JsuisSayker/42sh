/*
** EPITECH PROJECT, 2023
** is_sep_is_option
** File description:
** verify if the sep is an option
*/

#include <stdbool.h>
#include <stdio.h>
#include "my_str.h"

int is_a_sep(char c, char *separator)
{
    for (int i = 0; i <= my_strlen(separator); i += 1) {
        if (c == separator[i])
            return true;
    }
    return false;
}

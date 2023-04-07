/*
** EPITECH PROJECT, 2023
** return the len of an str
** File description:
** len_of_an_str
*/

#include <stdbool.h>
#include <stdio.h>
#include "my_str.h"

int len_of_an_str(char *str, int count, char *separator)
{
    int i = count;
    while (str[i] != '\0') {
        if (str[i] != '\0' && my_char_isalpha(str[i]) == false &&
        is_a_sep(str[i], separator) == false) {
            return i;
        }
        i += 1;
    }
    return i;
}

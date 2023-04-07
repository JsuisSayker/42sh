/*
** EPITECH PROJECT, 2023
** not a char in the str for split_in_env
** File description:
** not_a_char_in_str
*/

#include <stdbool.h>
#include "my_str.h"

void not_a_char_in_str(char *str, int *count, char *separator)
{
    while (my_char_isalpha(str[(*count)]) == false &&
    is_a_sep(str[(*count)], separator) == false) {
        (*count) += 1;
    }
}

/*
** EPITECH PROJECT, 2022
** my_strstr
** File description:
** str
*/

#include <stddef.h>
#include <stdbool.h>
#include "my_str.h"

static int my_str_pointer_cmp(char const *s1, char const *s2)
{
    if (s1 == NULL || s2 == NULL)
        return -1;
    while (*s1 != ' ') {
        if (*s1 - *s2 != 0) {
            return false;
        }
        s1 += 1;
        s2 += 1;
    }
    return true;
}

char *my_strstr(char *str, char const *to_find)
{
    for (int i = 0; str[i] != '\0'; i += 1) {
        if ((*str == *to_find) && my_str_pointer_cmp(str, to_find) == true) {
            return str;
        }
        str += 1;
    }
    return NULL;
}

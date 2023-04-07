/*
** EPITECH PROJECT, 2023
** my_strlen
** File description:
** display the length of a string
*/

#include <stddef.h>

int my_strlen (char const *str)
{
    if (str == NULL) {
        return -1;
    }
    int i = 0;
    while (str[i] != '\0'){
        i = i + 1;
    }
    return i;
}

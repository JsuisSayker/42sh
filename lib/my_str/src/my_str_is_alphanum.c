/*
** EPITECH PROJECT, 2023
** my_char_isalphanum.c
** File description:
** verify if the char is an alphanum
*/

#include <stdbool.h>
#include <stdio.h>

int my_str_is_alphanum(const char *str)
{
    for (int i = 0; str[i] != '\0'; i += 1) {
        if (!((str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z')
        || (str[i] >= '0' && str[i] <= '9')))
            return false;
    }
    return true;
}

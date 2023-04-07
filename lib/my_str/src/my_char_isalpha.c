/*
** EPITECH PROJECT, 2023
** verify if its an str
** File description:
** my_char_isalpha
*/

#include <stdbool.h>

int my_char_isalpha(const char c)
{
    if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z'){
        return true;
    }
    return false;
}

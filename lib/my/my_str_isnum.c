/*
** EPITECH PROJECT, 2022
** my_str_isnum
** File description:
** A faire
*/

#include <unistd.h>

#include "macro.h"

int my_str_isnum(char const *str)
{
    if (str == NULL)
        return KO;
    for (int i = 0; str[i] != '\0'; i ++){
        if (str[i] < '0' || str[i] > '9')
            return KO;
    }
    return OK;
}

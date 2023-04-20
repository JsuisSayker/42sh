/*
** EPITECH PROJECT, 2023
** lib
** File description:
** my_str_isalpha_num
*/

#include <unistd.h>
#include "macro.h"

int my_str_isalpha_num(char const *str, int i)
{
    if (str == NULL)
        return KO;
    if ((str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') &&
    (str[i] < '0' || str[i] > '9'))
        return KO;
    return OK;
}

int my_all_str_isalpha_num(char const *str)
{
    if (str == NULL)
        return KO;
    for (int i = 0; str[i] != '\0'; i ++){
        if ((str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') &&
        (str[i] < '0' || str[i] > '9'))
            return KO;
    }
    return OK;
}

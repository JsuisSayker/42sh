/*
** EPITECH PROJECT, 2022
** my_putstr
** File description:
** A faire
*/

#include <unistd.h>

#include "my.h"
#include "macro.h"

int my_putstr(char const *str)
{
    if (str == NULL)
        return KO;
    for (int i = 0; str[i] != '\0'; i ++){
        if (my_putchar(str[i]) == KO)
            return KO;
    }
    return OK;
}

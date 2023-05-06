/*
** EPITECH PROJECT, 2022
** Lib
** File description:
** reproduit le comportement de strcmp
*/

#include <unistd.h>

#include "macro.h"

int my_strcmp(char const *s1, char const *s2)
{
    if (s1 == NULL || s2 == NULL)
        return KO;
    for (int count = 0; s1[count] != '\0' && s2[count] != '\0'; count ++){
        if (s1[count] - s2[count] != 0)
            return KO;
    }
    return OK;
}

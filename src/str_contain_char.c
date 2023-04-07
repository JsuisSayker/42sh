/*
** EPITECH PROJECT, 2023
** B-PSU-200-BDX-2-1-minishell1-tom.mendy
** File description:
** str_contain_char
*/

#include <stdlib.h>

int str_contain_char(char *str, char c)
{
    if (str == NULL)
        return -1;
    for (int i = 0; str[i] != '\0'; i += 1) {
        if (str[i] == c)
            return 1;
    }
    return 0;
}

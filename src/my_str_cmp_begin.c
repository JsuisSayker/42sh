/*
** EPITECH PROJECT, 2023
** B-PSU-200-BDX-2-1-minishell1-tom.mendy
** File description:
** my_str_cmp_begin
*/

#include <stdlib.h>

int my_str_cmp_begin(char const *s1, char const *s2)
{
    if (s1 == NULL || s2 == NULL)
        return -1;
    for (int i = 0; s1[i] != '\0' && s2[i] != '\0'; i += 1) {
        if (s1[i] - s2[i] != 0)
            return 1;
    }
    return 0;
}

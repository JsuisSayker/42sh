/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** is_redirector
*/

#include "stddef.h"
#include "my_str.h"

int is_redirector(char const *s1, char const *s2)
{
    if (s1 == NULL || s2 == NULL)
        return -1;
    int i = 0;
    for (; s1[i] != '\0' && s2[i] != '\0'; i += 1) {
        if (s1[i] - s2[i] != 0)
            return 1;
    }
    if (s1[i] == s2[my_str_len(s2) - 1])
        return 1;
    return 0;
}

/*
** EPITECH PROJECT, 2023
** B-PSU-200-BDX-2-1-minishell1-tom.mendy
** File description:
** pwd_function
*/

#include <stdlib.h>
#include <unistd.h>

char *pwd_function(void)
{
    char *str = malloc(sizeof(char) * 100);
    for (int i = 0; i < 100; i += 1) {
        str[i] = '\0';
    }
    char *value = getcwd(str, 100);
    return value;
}

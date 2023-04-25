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
    char *str = NULL;
    char *value = getcwd(str, 0);
    return value;
}

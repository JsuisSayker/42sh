/*
** EPITECH PROJECT, 2023
** Minishell1
** File description:
** check_argc_argv
*/

#include <stddef.h>

#include "macro.h"

int check_argc_argv(int ac, char const *const *av)
{
    if (ac != 1)
        return KO;
    if (av[1] != NULL)
        return KO;
    return OK;
}

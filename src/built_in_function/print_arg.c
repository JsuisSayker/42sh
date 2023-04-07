/*
** EPITECH PROJECT, 2023
** B-PSU-200-BDX-2-1-bsminishell1-tom.mendy
** File description:
** print_arg
*/

#include "mysh.h"

int print_arg(char **arg)
{
    for (int i = 0; arg[i] != NULL; i += 1) {
        my_put_str(arg[i]);
        my_put_char('\n');
    }
    return 0;
}

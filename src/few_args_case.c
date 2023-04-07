/*
** EPITECH PROJECT, 2023
** few_args_case
** File description:
** a side function for unsetenv
*/

#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#include "minishell.h"

int few_args_case(char **args)
{
    if (args[1] == NULL) {
        write(2, "unsetenv: Too few arguments.\n", 29);
        free_command(args);
        return KO;
    }
    return OK;
}

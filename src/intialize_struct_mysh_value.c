/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** intialize_struct_mysh_value
*/

#include "mysh.h"

int intialize_struct_mysh_value(mysh_t *mysh_need, char **env)
{
    mysh_need->action_built_in = 1;
    mysh_need->buffer = NULL;
    mysh_need->return_value = 0;
    mysh_need->env = env;
    return 0;
}

/*
** EPITECH PROJECT, 2023
** unset_command
** File description:
** the command that will be unset
*/

#include "minishell.h"

void unset_command(char *command_eq, char **args, int i)
{
    command_eq[0] = '\0';
    my_strcat(command_eq, args[i]);
    my_strcat(command_eq, "=");
}

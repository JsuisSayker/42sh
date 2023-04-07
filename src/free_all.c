/*
** EPITECH PROJECT, 2023
** B-PSU-200-BDX-2-1-minishell1-tom.mendy
** File description:
** free_all
*/

#include "mysh.h"

void free_all(mysh_t *mysh_need)
{
    free_map(mysh_need->env);
    free(mysh_need->buffer);
}

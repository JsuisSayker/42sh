/*
** EPITECH PROJECT, 2023
** B-PSU-200-BDX-2-1-minishell1-tom.mendy
** File description:
** change_directory
*/

#include "mysh.h"

int change_directory(mysh_t *mysh_need)
{
    if (home_change_directory(mysh_need) == 0)
        return 0;
    if (previous_change_directory(mysh_need) == 0)
        return 0;
    else
        return default_change_directory(mysh_need);
}

/*
** EPITECH PROJECT, 2023
** B-PSU-200-BDX-2-1-minishell1-tom.mendy
** File description:
** display_too_many_argument
*/

#include "mysh.h"

int display_too_many_argument(char **str_split)
{
    if (my_map_len(str_split) > 2) {
        write(2, "cd: Too many arguments.\n", 24);
        return 0;
    }
    return 1;
}

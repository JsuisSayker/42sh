/*
** EPITECH PROJECT, 2023
** B-PSU-200-BDX-2-1-minishell1-tom.mendy
** File description:
** display_error
*/

#include "mysh.h"

void display_error(char **str_split, int return_cd)
{
    if (return_cd == -1) {
        if (str_contain_char(str_split[1], '-') == 1)
            write(2, "Usage: cd [-plvn][-|<dir>].\n", 28);
        if (display_too_many_argument(str_split) == 1)
            perror(str_split[1]);
    }
}

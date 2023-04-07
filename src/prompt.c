/*
** EPITECH PROJECT, 2023
** B-PSU-200-BDX-2-1-minishell1-tom.mendy
** File description:
** prompt
*/

#include "mysh.h"
#include <sys/stat.h>

void prompt(void)
{
    struct stat s;
    fstat(0, &s);
    if (!S_ISFIFO(s.st_mode))
        my_put_str("$> ");
}

/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** is_str_redirector
*/

#include "mysh.h"

int is_str_redirector(char * str)
{
    if (str == NULL)
        return -1;
    char *redirector[] = { ";", "|", ">>", ">", "<<", "<", NULL };
    for (int i = 0; redirector[i] != NULL; i += 1){
        if (my_str_cmp(str, redirector[i]) == 0)
            return 1;
    }
    return 0;
}

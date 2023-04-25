/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** alias
*/

#include <unistd.h>

#include "macro.h"
#include "proto.h"
#include "proto_lib.h"

int history(base_minishell_t *base, char **tab)
{
    if (tab == NULL)
        return KO;
    char *tmp_pwd = my_strcat(base->pwd, "/.history.txt");
    if (display_file(tmp_pwd) == KO)
        return KO;
    free(tmp_pwd);
    return OK;
}

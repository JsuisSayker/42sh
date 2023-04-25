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

int alias(base_minishell_t *base, char **tab)
{
    if (tab == NULL)
        return KO;
    char *tmp_pwd = my_strcat(base->pwd, "//.alias.txt");
    if (tmp_pwd == NULL)
        return KO;
    switch (my_tablen(tab)){
    case 1:
        display_file(tmp_pwd);
        break;
    case 2:
        display_file(tmp_pwd);
        break;
    case 3:
        display_file(tmp_pwd);
        break;
    default:
        return 0;
    }
    free(tmp_pwd);
    return OK;
}

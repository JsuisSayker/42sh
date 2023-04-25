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
    char *tmp_pwd = my_strcat(base->pwd, "/.alias.txt");
    if (tmp_pwd == NULL)
        return KO;
    switch (my_tablen(tab)){
    case 1:
        display_file(tmp_pwd);
        free(tmp_pwd);
        break;
    case 2:
        display_file(tmp_pwd);
        free(tmp_pwd);
        break;
    case 3:
        char *line = my_strcat(tab[1], " ");
        char *line_final = my_strcat(line, tab[2]);
        free(line);
        char *line_final_aze = my_strcat(line_final, tab[2]);
        free(line_final);
        append_str_to_file(tmp_pwd, line_final_aze);
        free(tmp_pwd);
        break;
    default:
        return 0;
    }
    return OK;
}

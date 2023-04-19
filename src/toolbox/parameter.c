/*
** EPITECH PROJECT, 2023
** Minishell2
** File description:
** take_parameter
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include "macro.h"
#include "struct.h"
#include "proto_lib.h"

int check_if_redirector(char *str, need_tab_t *need_tab)
{
    if (str[0] == '|')
        return OK;
    if (str[0] == ';')
        return OK;
    if (str[0] == '<'){
        need_tab->redirect_arg = 1;
        return OK;
    }
    if (str[0] == '>'){
        need_tab->redirect_arg = 2;
        return OK;
    }
    return KO;
}

int count_parameter(char *str)
{
    int x = 0;
    int nbr_parameter = 0;
    if (str == NULL)
        return KO;
    while (str[x] != '\0'){
        if (str[x] == '|' || (str[x] == '>' && str[x + 1] != '>' &&
        str[x - 1] != '>') || (str[x] == '<' && str[x + 1] != '<' &&
        str[x - 1] != '<'))
            nbr_parameter += 1;
        if ((str[x] == '>' && str[x + 1] == '>') ||
        (str[x] == '<' && str[x + 1] == '<')){
            nbr_parameter += 1;
            x += 1;
        }
        x += 1;
    }
    return nbr_parameter;
}

int take_parameter(char *str)
{
    int x = 0;
    int nbr_parameter = 0;
    if (str == NULL)
        return KO;
    while (str[x] != '\0'){
        if (str[x] == '|' || (str[x] == '>' && str[x + 1] != '>' &&
        str[x - 1] != '>') || (str[x] == '<' && str[x + 1] != '<' &&
        str[x - 1] != '<') || str[x] == ';')
            nbr_parameter += 1;
        if ((str[x] == '>' && str[x + 1] == '>') ||
        (str[x] == '<' && str[x + 1] == '<')){
            nbr_parameter += 1;
            x += 1;
        }
        x += 1;
    }
    return nbr_parameter;
}

int count_parameter_sub(char **tab)
{
    int nbr_parameter = 0;
    if (tab == NULL)
        return KO;
    for (int x = 0; tab[x] != NULL; x += 1){
        if (tab[x][0] == '|' || (tab[x][0] == '>' && my_tablen(tab) < 2)
        || (tab[x][0] == '<' && my_tablen(tab) < 2))
            nbr_parameter += 1;
        if ((tab[x][0] == '>' && my_tablen(tab) > 1)
        || (tab[x][0] == '<' && my_tablen(tab) > 1))
            nbr_parameter += 1;
    }
    return nbr_parameter;
}

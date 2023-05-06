/*
** EPITECH PROJECT, 2023
** Minishell1
** File description:
** free_tab
*/

#include <unistd.h>
#include <stdlib.h>

#include "struct.h"
#include "macro.h"

int free_big_tab(char ***tab)
{
    if (tab == NULL)
        return KO;
    for (int y = 0; tab[y] != NULL; y += 1) {
        for (int x = 0; tab[y][x] != NULL; x += 1) {
            free(tab[y][x]);
        }
        free(tab[y]);
    }
    free(tab);
    return OK;
}

int free_tab_char(char **tab)
{
    if (tab == NULL)
        return KO;
    for (int i = 0; tab[i] != NULL; i += 1){
        free(tab[i]);
    }
    free(tab);
    return OK;
}

int free_tab_int(need_tab_t *need_tab)
{
    if (need_tab == NULL)
        return KO;
    for (int i = 0; i < need_tab->nbr_parameter; i += 1){
        free(need_tab->fd[i]);
    }
    free(need_tab->fd);
    return OK;
}

int free_str(all_str_t *all_str)
{
    free(all_str->str);
    free(all_str);
    return OK;
}

int free_all(base_minishell_t *base, need_tab_t *need_tab, char **tab)
{
    free_tab_char(base->env);
    free_tab_char(base->path);
    free_tab_char(base->command);
    if (base->yes_or_not == 1)
        free_big_tab(base->p_command);
    free(need_tab);
    free(base->pwd);
    free(base);
    free(tab);
    return OK;
}

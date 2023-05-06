/*
** EPITECH PROJECT, 2023
** Minishell2
** File description:
** command_with_parameter
*/

#include <unistd.h>

#include "proto.h"
#include "macro.h"
#include "struct.h"
#include "proto_lib.h"

static int initialisation_value(base_minishell_t *base, need_tab_t *need_tab)
{
    int tab_len = 0;
    if ((tab_len = my_tablen(base->p_command[need_tab->tab_pos_y])) == OK)
        return KO;
    if ((need_tab->nbr_parameter =
    count_parameter(base->command[need_tab->tab_pos_y])) == KO)
        return KO;
    if (need_tab->nbr_parameter == 0)
        return OK;
    need_tab->tab_len = tab_len - 1;
    need_tab->nbr_parameter += 1;
    need_tab->fd_pos = 0;
    if ((need_tab->fd = malloc(sizeof(int *) * (need_tab->nbr_parameter)))
    == NULL)
        return KO;
    need_tab->fd[need_tab->nbr_parameter - 1] = NULL;
    for (int x = 0; x < need_tab->nbr_parameter; x ++){
        if ((need_tab->fd[x] = malloc(sizeof(int) * 2)) == NULL)
            return KO;
    }
    return OK;
}

static int malloc_pipe(need_tab_t *need_tab)
{
    if (need_tab == NULL)
        return KO;
    printf("-----------------------------------------------\n");
    for (int x = 0; x < need_tab->nbr_parameter; x ++){
        if (pipe(need_tab->fd[x]) != OK)
            return KO;
        printf("fd pipe -> [%d]\n", x);
        }
    printf("-----------------------------------------------\n");
    return OK;
}

static int command_with_parameter_sub(base_minishell_t *base,
need_tab_t *need_tab)
{
    if (base == NULL || need_tab == NULL)
        return KO;
    if (need_tab->nbr_parameter == 0)
        base->yes_or_not = 0;
    else{
        if (malloc_pipe(need_tab) != OK)
            return KO;
    }
    for (int x = 0; base->p_command[need_tab->tab_pos_y][x] != NULL; x += 1){
        if (check_if_redirector(base->p_command[need_tab->tab_pos_y][x],
        need_tab) == OK){
            need_tab->fd_pos += 1;
            continue;
        }
        need_tab->tab_pos_x = x;
        if (child_display_parameter(base, need_tab) != OK)
            return KO;
    }
    free_tab_int(need_tab);
    return OK;
}

int command_with_parameter(base_minishell_t *base, need_tab_t *need_tab)
{
    if (base == NULL || need_tab == NULL)
        return KO;
    for (int y = 0; base->p_command[y] != NULL; y += 1){
        base->yes_or_not = 1;
        base->return_value = 0;
        need_tab->tab_pos_y = y;
        if (initialisation_value(base, need_tab) != OK)
            return KO;
        if (command_with_parameter_sub(base, need_tab) != OK)
            return KO;
    }
    return OK;
}

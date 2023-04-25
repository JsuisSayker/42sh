/*
** EPITECH PROJECT, 2023
** Minishell2
** File description:
** fonction_build
*/


#include <unistd.h>

#include "macro.h"
#include "proto.h"
#include "struct.h"
#include "proto_lib.h"

int parameter_after_command(base_minishell_t *base, need_tab_t *need_tab)
{
    if (need_tab->tab_pos_x + 1 < need_tab->tab_len){
        if (my_strncmp("|", base->p_command[need_tab->tab_pos_y]
        [need_tab->tab_pos_x + 1], 1) == OK)
            return OK;
        if (my_strncmp(">", base->p_command[need_tab->tab_pos_y]
        [need_tab->tab_pos_x + 1], 1) == OK)
            return OK;
        if (my_strncmp("<", base->p_command[need_tab->tab_pos_y]
        [need_tab->tab_pos_x + 1], 1) == OK)
            return OK;
        if (my_strncmp(">>", base->p_command[need_tab->tab_pos_y]
        [need_tab->tab_pos_x + 1], 2) == OK)
            return OK;
        if (my_strncmp("<<", base->p_command[need_tab->tab_pos_y]
        [need_tab->tab_pos_x + 1], 2) == OK)
            return OK;
    }
    return KO;
}

int execution_fonction_build(base_minishell_t *base, char **tab, int n)
{
    if (n == 0){
        if (cd_reprogramming(base, tab) != OK)
            base->return_value = 1;
    }
    if (n == 1){
        if (unsetenv_exit(base, tab) != OK)
            base->return_value = 1;
    }
    if (n == 2){
        if (setenv_exit(base, tab) != OK)
            base->return_value = 1;
    }
    return OK;
}

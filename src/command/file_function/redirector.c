/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** redirector
*/

#include <unistd.h>
#include <string.h>
#include <fcntl.h>

#include "proto.h"
#include "macro.h"
#include "proto_lib.h"

static int file_function_ter(base_minishell_t *base, need_tab_t *need_tab)
{
    if (!base || !need_tab)
        return KO;
    if (strcmp("<<", base->p_command[need_tab->tab_pos_y]\
    [need_tab->tab_pos_x + 1]) == OK){
        if (child_display_parameter(base, need_tab) == OK)
            return OK;
    }
    return OK;
}

static int file_function_sub(base_minishell_t *base, need_tab_t *need_tab,
char **tab_command, int *x)
{
    if (need_tab->redirect_arg == 2) {
        need_tab->redirect_arg = 0;
        if (right_redirector(base, need_tab, tab_command) != OK) {
            base->return_value = 1;
            return OK;
        }
    }
    if (need_tab->redirect_arg == 1) {
        if ((need_tab->nbr_parameter - 1) == 1)
            base->yes_or_not = 0;
        file_function_ter(base, need_tab);
        if (command(base, need_tab, tab_command) != OK)
            return KO;
        need_tab->redirect_arg = 0;
        *x += 2;
    }
    return 1;
}

int file_function(base_minishell_t *base, need_tab_t *need_tab, int *x)
{
    char **tab_command = NULL;
    if (base == NULL || need_tab == NULL)
        return KO;
    tab_command = my_splitstr(base->p_command[need_tab->tab_pos_y]\
    [need_tab->tab_pos_x], ' ');
    if (file_function_sub(base, need_tab, tab_command, x) != KO){
        return OK;
    }
    free_tab_char(tab_command);
    return OK;
}

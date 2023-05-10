/*
** EPITECH PROJECT, 2023
** special_exec.c
** File description:
** special_exec
*/

#include "proto.h"
#include "macro.h"

int special_exec(base_minishell_t *base, need_tab_t *need_tab, int *x,
int *client)
{
    if (need_tab->special_exec != 0) {
        if (execute_cmd_and_cmd(base, need_tab) != OK)
            return KO;
        (*client) = 1;
        return OK;
    }
    if (need_tab->redirect_arg != 0){
        if (file_function(base, need_tab, x) != OK)
            return KO;
        (*client) = 1;
        return OK;
    }
    (*client) = 0;
    return OK;
}

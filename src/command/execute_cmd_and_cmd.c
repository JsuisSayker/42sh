/*
** EPITECH PROJECT, 2023
** execute_cmd_and_cmd
** File description:
** execute_cmd_and_cmd
*/

#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "proto.h"
#include "proto_lib.h"
#include "macro.h"

int execute_cmd_and_cmd(base_minishell_t *base, need_tab_t *need_tab)
{
    if (base == NULL || need_tab == NULL)
        return KO;
    need_tab->special_exec = 0;
    char **cmds_to_execute_simultaneously = my_splitstr(base->p_command
    [need_tab->tab_pos_y] [need_tab->tab_pos_x], ' ');
    free_tab_char(cmds_to_execute_simultaneously);
    return OK;
}

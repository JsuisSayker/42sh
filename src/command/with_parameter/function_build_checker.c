/*
** EPITECH PROJECT, 2023
** Minishell_two
** File description:
** build_function_w_parameter_checker
*/

#include <stdio.h>

#include "macro.h"
#include "proto.h"
#include "struct.h"
#include "proto_lib.h"

const struct function FUNCS_POINTERS[] = {
    {"unsetenv", &unsetenv_exit},
    {"cd", &cd_reprogramming},
    {"alias", &alias},
    {"NULL", NULL}
};

static int parameter_after_command(base_minishell_t *base, need_tab_t *need_tab)
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

static int check_function_build_ter(base_minishell_t *base, char **tab_command)
{
    int len_tab = 0;
    if (my_strncmp("exit", tab_command[0], 4) == OK){
        base->exit = 1;
        return OK;
    }
    if (my_strncmp("setenv", tab_command[0], 6) == OK){
        if ((len_tab = my_tablen(tab_command)) <= 2)
            return KO;
        else {
            base->return_value = setenv_exit(base, tab_command);
            return OK;
        }
    }
    return KO;
}

int check_function_build_sub(base_minishell_t *base, need_tab_t *need_tab,
char **tab_command, int i)
{
    int len_str = 0;
    if ((len_str = my_strlen(FUNCS_POINTERS[i].str)) == KO)
            return KO;
    if (my_strncmp(FUNCS_POINTERS[i].str, tab_command[0], len_str) ==
    OK){
        if (parameter_after_command(base, need_tab) == OK)
            return OK;
        if (FUNCS_POINTERS[i].proto(base, tab_command) != OK)
            base->return_value = 1;
        return OK;
    }
    return KO;
}

int check_function_build(base_minishell_t *base, need_tab_t *need_tab,
char **tab_command)
{
    for (int i = 0; my_strncmp("NULL", FUNCS_POINTERS[i].str, 4) != OK; i ++){
        if (check_function_build_sub(base, need_tab, tab_command, i)
        == OK)
            return OK;
    }
    if (check_function_build_ter(base, tab_command) == OK)
        return OK;
    return KO;
}

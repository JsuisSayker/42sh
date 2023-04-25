/*
** EPITECH PROJECT, 2023
** Minishell1
** File description:
** command_checker
*/

#include <unistd.h>

#include "proto.h"
#include "macro.h"
#include "struct.h"
#include "proto_lib.h"

const struct fonction OPERATORS_FUNCS[] = {
    {"setenv", &setenv_exit},
    {"unsetenv", &unsetenv_exit},
    {"cd", &cd_reprogramming},
    {"NULL", NULL}
};

static int check_reprograming_command_sub(base_minishell_t *base,
int *reprograming_command)
{
    if (my_strncmp("exit", base->command[0], 4) == OK){
        *reprograming_command = 1;
        base->exit = 1;
        return OK;
    }
    if (my_strncmp("!", base->command[0], 1) == OK){
        *reprograming_command = 1;
        if (display_file(".save/history.txt") != OK)
            return KO;
        return OK;
    }
    return OK;
}

static int check_reprograming_command(base_minishell_t *base,
int *reprograming_command)
{
    int len_str = 0;
    for (int i = 0; my_strncmp("NULL", OPERATORS_FUNCS[i].str, 4) != OK; i ++){
        if ((len_str = my_strlen(OPERATORS_FUNCS[i].str)) == KO)
            return KO;
        if (my_strncmp(OPERATORS_FUNCS[i].str, base->command[0], len_str) ==
        OK){
            *reprograming_command = 1;
            return OPERATORS_FUNCS[i].proto(base, base->command);
        }
    }
    if (check_reprograming_command_sub(base, reprograming_command) == OK)
        return OK;
    return KO;
}

int check_command_and_execute(base_minishell_t *base, need_tab_t *need_tab)
{
    int reprograming_command = 0;
    if (base == NULL)
        return KO;
    if (check_reprograming_command(base, &reprograming_command) != 0)
        base->return_value = 1;
    if (reprograming_command != 0)
        return OK;
    if (command(base, need_tab, base->command) != 0)
        base->return_value = 1;
    return OK;
}

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

static int check_reprograming_command_sub(base_minishell_t *base,
int *reprograming_command)
{
    if (my_strncmp("unsetenv", base->command[0], 8) == OK){
        *reprograming_command = 1;
        if (unsetenv_exit(base, base->command) != OK)
            return KO;
        return OK;
    }
    if (my_strncmp("setenv", base->command[0], 6) == OK){
        *reprograming_command = 1;
        if (setenv_exit(base, base->command) != OK)
            return KO;
        return OK;
    }
    if (my_strncmp("cd", base->command[0], 2) == OK){
        *reprograming_command = 1;
        if (cd_reprogramming(base, base->command) != OK)
            return KO;
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
    if (my_strncmp("exit", base->command[0], 4) == OK){
        *reprograming_command = 1;
        base->exit = 1;
        return OK;
    }
    if (my_strncmp("env", base->command[0], 3) == OK){
        *reprograming_command = 1;
        if (print_env(base->env) != OK)
            return KO;
        return OK;
    }
    if (check_reprograming_command_sub(base, reprograming_command) != OK)
        return KO;
    return OK;
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

/*
** EPITECH PROJECT, 2023
** Minishell_two
** File description:
** build_fonction_w_parameter_checker
*/

#include "macro.h"
#include "proto.h"
#include "struct.h"
#include "proto_lib.h"

static int fonction_build_sub(base_minishell_t *base, need_tab_t *need_tab,
char **tab_command, int len_tab)
{
    if (len_tab = my_tablen(tab_command) > 1)
        return OK;
    else{
        if (print_env(base->env) != OK)
            base->return_value = 1;
    }
    return KO;
}

int fonction_build(base_minishell_t *base, need_tab_t *need_tab,
char **tab_command)
{
    int len_tab = 0;
    if (my_strncmp("setenv", tab_command[0], 6) == OK){
        if (fonction_build_sub(base, need_tab, tab_command, len_tab) == OK)
            return OK;
        return OK;
    }
    if (my_strncmp("env", tab_command[0], 3) == OK){
        if (print_env(base->env) != OK)
            base->return_value = 1;
        return OK;
    }
    return KO;
}

static int check_fontion_build_sub(base_minishell_t *base, need_tab_t *need_tab,
char **tab_command)
{
    int len_tab = 0;
    if (my_strncmp("exit", tab_command[0], 4) == OK){
        if (parameter_after_command(base, need_tab) == OK)
            return OK;
        base->exit = 1;
        return OK;
    }
    if (my_strncmp("setenv", tab_command[0], 6) == OK){
        if (len_tab = my_tablen(tab_command) < 2 &&
        parameter_after_command(base, need_tab) == OK)
            return KO;
        else
            execution_fonction_build(base, tab_command, 2);
            return OK;
    }
    return KO;
}

int check_fontion_build(base_minishell_t *base, need_tab_t *need_tab,
char **tab_command)
{
    if (my_strncmp("unsetenv", tab_command[0], 8) == OK){
        if (parameter_after_command(base, need_tab) == OK)
            return OK;
        else
            execution_fonction_build(base, tab_command, 1);
        return OK;
    }
    if (my_strncmp("cd", tab_command[0], 2) == OK){
        if (parameter_after_command(base, need_tab) == OK)
            return OK;
        else
            execution_fonction_build(base, tab_command, 0);
        return OK;
    }
    if (check_fontion_build_sub(base, need_tab, tab_command) == OK)
        return OK;
    return KO;
}

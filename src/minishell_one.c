/*
** EPITECH PROJECT, 2023
** Minishell1
** File description:
** minishell_one
*/

#include <unistd.h>

#include "proto.h"
#include "macro.h"
#include "struct.h"
#include "proto_lib.h"

static void add_value(need_tab_t *need_tab)
{
    need_tab->aft_arg = 0;
    need_tab->fd_pos = 0;
    need_tab->nbr_parameter = 0;
    need_tab->redirect_arg = 0;
    need_tab->tab_len = 0;
    need_tab->tab_pos_x = 0;
    need_tab->tab_pos_y = 0;
}

static int minishell_two(base_minishell_t *base, need_tab_t *need_tab,
int *nbr_parameter)
{
    if (base == NULL || need_tab == NULL)
        return 1;
    if (*nbr_parameter == 0){
        base->yes_or_not = 0;
        if (check_command_and_execute(base, need_tab) != 0)
                return 1;
    } else {
        base->yes_or_not = 1;
        if (command_with_parameter(base, need_tab) != OK)
            return 1;
        if (free_big_tab(base->p_command) != OK)
            return 1;
    }
    *nbr_parameter = 0;
    if (free_tab_char(base->command) != OK)
        return 1;
    return OK;
}

static int minishell_one_sub(base_minishell_t *base, char **env)
{
    need_tab_t *need_tab = malloc(sizeof(need_tab_t));
    base->exit = 0;
    int echo_or_not = 0;
    add_value(need_tab);
    int restart = 0;
    int nbr_parameter = 0;
    if (base == NULL || env == NULL)
        return 1;
    while (base->exit != 1){
        if ((echo_or_not = starting()) == -1)
            return 1;
        if (take_entry(base, env, &restart, &nbr_parameter) != OK)
            break;
        if (restart == 1)
            continue;
        if (minishell_two(base, need_tab, &nbr_parameter) != OK)
            return 1;
    }
    free(need_tab);
    return base->return_value;
}

int minishell_one(int ac, char const *const *av, char **env)
{
    int return_value = 0;
    base_minishell_t *base = malloc(sizeof(base_minishell_t));
    if (base == NULL || env == NULL)
        return 1;
    base->path = take_path(env, "PATH=");
    if (base->path == NULL)
        return 1;
    base->env = take_env(env);
    base->pwd = pwd_function();
    return_value = minishell_one_sub(base, env);
    free_tab_char(base->path);
    free_tab_char(base->env);
    free(base->pwd);
    free(base);
    return return_value;
}

/*
** EPITECH PROJECT, 2023
** Minishell2
** File description:
** command_with_pipe
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <sys/wait.h>

#include "proto.h"
#include "macro.h"
#include "struct.h"
#include "proto_lib.h"

static void wait_function(need_tab_t *need_tab, pid_t pid, int *value)
{
    if (need_tab->tab_len < 1 || need_tab->tab_len == need_tab->tab_pos_x)
        waitpid(pid, value, WUNTRACED);
    else
        waitpid(pid, value, WUNTRACED | WNOHANG);
}

static void child_display_sub(int value)
{
    if (WCOREDUMP(value) == 128)
        write(2, " (core dumped)", 14);
    if (WTERMSIG(value) == 8 || WTERMSIG(value) == 11)
        write(1, "\n", 1);
}

int child_display(base_minishell_t *base, need_tab_t *need_tab,
pid_t pid, int value)
{
    close_function(base, need_tab);
    wait_function(need_tab, pid, &value);
    base->return_value = WEXITSTATUS(value) + WTERMSIG(value) +
    WCOREDUMP(value);
    if (WTERMSIG(value) == 8)
        write(2, "Floating execption", 18);
    if (WTERMSIG(value) == 11)
        write(2, "Segmentation fault", 18);
    child_display_sub(value);
    return OK;
}

int child_display_parameter(base_minishell_t *base, need_tab_t *need_tab)
{
    char **tab_command = NULL;
    if (base == NULL || need_tab == NULL)
        return KO;
    tab_command = my_splitstr(base->p_command[need_tab->tab_pos_y]
    [need_tab->tab_pos_x], ' ');
    if (check_function_build(base, need_tab, tab_command) == OK){
        free_tab_char(tab_command);
        return OK;
    }
    if (command(base, need_tab, tab_command) != OK){
        free_tab_char(tab_command);
        return KO;
    }
    free_tab_char(tab_command);
    return OK;
}

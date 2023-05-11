/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** left_or_right_redirector
*/

#include <unistd.h>
#include <string.h>

#include "proto.h"
#include "macro.h"
#include "proto_lib.h"

static int close_and_free_function(need_tab_t *need_tab, char **command,
char *str)
{
    if (!need_tab || !command || !str)
        return KO;
    free_tab_char(command);
    free(str);
    close(need_tab->fd[need_tab->fd_pos - 1][0]);
    close(need_tab->fd[need_tab->fd_pos - 1][1]);
    return OK;
}

int right_redirector(base_minishell_t *base, need_tab_t *need_tab,
char **command)
{
    char *str;
    if ((str = my_load_fd_in_memory(need_tab->fd[need_tab->fd_pos - 1][0]))
    == NULL)
        return KO;
    if (strcmp(">>", base->p_command\
    [need_tab->tab_pos_y][need_tab->tab_pos_x - 1]) == OK){
        append_stdout_to_file(command[0], str);
        if (close_and_free_function(need_tab, command, str) == KO)
            return KO;
        return OK;
    }
    if (strcmp(">", base->p_command[need_tab->tab_pos_y]\
    [need_tab->tab_pos_x - 1]) == OK){
        put_stdout_in_file(command[0], str);
        if (close_and_free_function(need_tab, command, str) == KO)
            return KO;
        return OK;
    }
    return 1;
}

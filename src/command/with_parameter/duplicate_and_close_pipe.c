/*
** EPITECH PROJECT, 2023
** Minishell2
** File description:
** duplicate_and_close_pipe
*/

#include <unistd.h>

#include "macro.h"
#include "proto.h"
#include "struct.h"
#include "proto_lib.h"

void close_fonction(base_minishell_t *base, need_tab_t *need_tab)
{
    if (base->yes_or_not == 1){
        if (need_tab->fd_pos > 0){
            close(need_tab->fd[need_tab->fd_pos - 1][0]);
            close(need_tab->fd[need_tab->fd_pos - 1][1]);
        }
    }
}

static void duplicate_fonction_sub(need_tab_t *need_tab)
{
    dup2(need_tab->fd[need_tab->fd_pos][1], STDOUT_FILENO);
    dup2(need_tab->fd[need_tab->fd_pos - 1][0], STDIN_FILENO);
    close(need_tab->fd[need_tab->fd_pos][0]);
    close(need_tab->fd[need_tab->fd_pos][1]);
    close(need_tab->fd[need_tab->fd_pos - 1][1]);
}

int duplicate_fonction(base_minishell_t *base, need_tab_t *need_tab)
{
    if (base->yes_or_not == 1){
        if (need_tab->tab_pos_x == 0) {
            dup2(need_tab->fd[need_tab->fd_pos][1], STDOUT_FILENO);
            close(need_tab->fd[need_tab->fd_pos][0]);
            close(need_tab->fd[need_tab->fd_pos][1]);
            return OK;
        }
        if (need_tab->tab_pos_x == need_tab->tab_len) {
            dup2(need_tab->fd[need_tab->fd_pos - 1][0], STDIN_FILENO);
            close(need_tab->fd[need_tab->fd_pos][1]);
            close(need_tab->fd[need_tab->fd_pos][0]);
            close(need_tab->fd[need_tab->fd_pos - 1][1]);
        } else {
            duplicate_fonction_sub(need_tab);
        }
    }
    return OK;
}

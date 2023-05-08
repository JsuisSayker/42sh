/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** redirector
*/

#include <unistd.h>
#include <string.h>
#include <fcntl.h>

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

static int right_redirector(base_minishell_t *base, need_tab_t *need_tab,
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

static int left_redirector(base_minishell_t *base, need_tab_t *need_tab,
char **tab_command, int *x)
{
    int fd = 0;
    if (strcmp(">", base->p_command[need_tab->tab_pos_y]\
    [need_tab->tab_pos_x + 1]) == OK){
        if ((fd = open(base->p_command[need_tab->tab_pos_y]\
        [need_tab->tab_pos_x + 2], O_RDONLY)) == -1)
            return KO;
        dup2(fd, STDIN_FILENO);
        base->yes_or_not = 0;
        if (command(base, need_tab, tab_command) != OK)
            return KO;
        *x += 2;
        return OK;
    }
    return OK;
}

int file_function(base_minishell_t *base, need_tab_t *need_tab, int *x)
{
    char **command = NULL;
    if (base == NULL || need_tab == NULL)
        return KO;
    command = my_splitstr(base->p_command[need_tab->tab_pos_y]\
    [need_tab->tab_pos_x], ' ');
    if (need_tab->redirect_arg == 2){
        need_tab->redirect_arg = 0;
        if (right_redirector(base, need_tab, command) == OK){
            return OK;
        }
    }
    if (need_tab->redirect_arg == 1){
        need_tab->redirect_arg = 0;
        if (left_redirector(base, need_tab, command, x) == OK){
            return OK;
        }
    }
    return KO;
}

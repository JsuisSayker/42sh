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

static int put_stdout_in_file(const char *filename, char *str)
{
    int fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
    if (fd == -1) {
        return -1;
    }
    write(fd, str, strlen(str));
    close(fd);
    return 0;
}

static int append_stdout_to_file(const char *filename, char *str)
{
    int fd = open(filename, O_CREAT | O_WRONLY | O_APPEND, S_IRWXU);
    if (fd == -1) {
        return -1;
    }
    write(fd, str, strlen(str));
    close(fd);
    return 0;
}

static int greater_than_function(base_minishell_t *base, need_tab_t *need_tab,
char **command)
{
    char *str;
    if (my_strcmp(">", base->p_command[need_tab->tab_pos_y]\
    [need_tab->tab_pos_x - 1]) == OK){
        printf("fd pos -> [%d]\n", need_tab->fd_pos);
        printf("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\n");
        str = my_load_fd_in_memory(need_tab->fd[need_tab->fd_pos - 1][0]);
        put_stdout_in_file(command[0], str);
        free(str);
        close(need_tab->fd[need_tab->fd_pos - 1][0]);
        close(need_tab->fd[need_tab->fd_pos - 1][1]);
        return OK;
    }
    return 1;
}

static int double_greater_than_function(base_minishell_t *base,
need_tab_t *need_tab, char **command)
{
    char *str;
    if (my_strcmp(">>", base->p_command\
    [need_tab->tab_pos_y][need_tab->tab_pos_x - 1]) == OK){
        str = my_load_fd_in_memory(need_tab->fd\
        [need_tab->fd_pos][0]);
        append_stdout_to_file(command[0], str);
        free(str);
        close(need_tab->fd[need_tab->fd_pos - 1][0]);
        close(need_tab->fd[need_tab->fd_pos - 1][1]);
        return OK;
    }
    return 1;
}

int file_function(base_minishell_t *base, need_tab_t *need_tab, char **command)
{
    if (need_tab->redirect_arg == 2){
        need_tab->redirect_arg = 0;
        if (greater_than_function(base, need_tab, command) == OK){
            return OK;
        }
        if (double_greater_than_function(base, need_tab, command) == OK)
            return OK;
    }
    return KO;
}

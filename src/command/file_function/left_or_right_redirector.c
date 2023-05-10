/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** left_or_right_redirector
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

int error_message(char *filename)
{
    int len = 0;
    if (!filename)
        return KO;
    if ((len = my_strlen(filename)) == KO)
        return KO;
    if (write(1, filename, len) == KO)
        return KO;
    if (write(1, ": No such file or directory.\n", 29) == KO)
        return KO;
    free(filename);
    return OK;
}

int left_redirector(base_minishell_t *base, need_tab_t *need_tab,
char **tab_command)
{
    char *filename = NULL;
    int fd;
    if ((filename = clean_str(base->p_command[need_tab->tab_pos_y]\
    [need_tab->tab_pos_x + 2])) == NULL)
        return KO;
    if (strcmp("<", base->p_command[need_tab->tab_pos_y]\
    [need_tab->tab_pos_x + 1]) == OK){
        if ((fd = open(filename, O_RDONLY)) == KO){
            error_message(filename);
            close(fd);
            return OK;
        }
        dup2(fd, STDIN_FILENO);
        close(fd);
        execution(base, need_tab, tab_command);
    }
    return OK;
}

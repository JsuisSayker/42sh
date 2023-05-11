/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** left_redirector_sub
*/

#include <unistd.h>
#include <string.h>
#include <fcntl.h>

#include "proto.h"
#include "macro.h"
#include "proto_lib.h"

static int error_message(char *filename)
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

int double_left_redirector_child(base_minishell_t *base, need_tab_t *need_tab,
char *filename, char **tab_command)
{
    int fd;
    int rm = 0;
    char *str;
    if (!base || !need_tab || !tab_command || !filename)
        return KO;
    if ((fd = open(filename, O_RDONLY)) == KO){
        close(fd);
        return OK;
    }
    if ((str = my_load_fd_in_memory(fd)) == NULL)
        return KO;
    dup2(fd, STDIN_FILENO);
    if ((rm = remove(filename)) != 0)
        return KO;
    close(fd);
    return OK;
}

int single_left_redirector(base_minishell_t *base, need_tab_t *need_tab,
char **tab_command)
{
    char *filename = NULL;
    int fd;
    if (!base || !need_tab || !tab_command)
        return KO;
    if ((filename = clean_str(base->p_command[need_tab->tab_pos_y]\
    [need_tab->tab_pos_x + 2])) == NULL)
        return KO;
    if ((fd = open(filename, O_RDONLY)) == KO){
        error_message(filename);
        close(fd);
        return OK;
    }
    dup2(fd, STDIN_FILENO);
    close(fd);
    return OK;
}

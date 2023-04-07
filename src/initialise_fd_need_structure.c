/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** initialise_fd_need_structure
*/

#include "mysh.h"

static int nb_redirector_function(char ***command_split)
{
    int count_redirector = 0;
    for (int i = 0; command_split[i] != NULL; i += 1) {
        if (is_str_redirector(command_split[i][0]) != OK)
            count_redirector += 1;
    }
    return count_redirector;
}

void initialise_fd_need_structure(char ***command_split, fd_need_t *fd_need_n)
{
    fd_need_n->index_pipe_fd = 0;
    fd_need_n->nb_redirector = nb_redirector_function(command_split);
    fd_need_n->all_pid = malloc(sizeof(pid_t) * fd_need_n->nb_redirector);
    fd_need_n->pipe_fd = malloc(sizeof(int *) * fd_need_n->nb_redirector);
    for (int i = 0; i < fd_need_n->nb_redirector; i += 1) {
        fd_need_n->pipe_fd[i] = malloc(sizeof(int) * (2));
    }
}

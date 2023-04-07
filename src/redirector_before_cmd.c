/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** redirector_before_cmd
*/

#include "mysh.h"

int redirector_before_cmd(mysh_t *mysh_need, fd_need_t *fd_need_n)
{
    if (is_str_redirector(mysh_need->command_split[mysh_need->nb_field\
        - 1][0]) != OK) {
        if (my_str_cmp(mysh_need->command_split[mysh_need->nb_field\
            - 1][0], "|") == OK){
            dup2(fd_need_n->pipe_fd[fd_need_n->index_pipe_fd - 1][0],\
            STDIN_FILENO);
        }
        close(fd_need_n->pipe_fd[fd_need_n->index_pipe_fd - 1][0]);
        close(fd_need_n->pipe_fd[fd_need_n->index_pipe_fd - 1][1]);
    }
    return 0;
}

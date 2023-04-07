/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** launch_command
*/

#include "mysh.h"

static void close_pipe_function(mysh_t *mysh_need, fd_need_t *fd_need_n)
{
    if (fd_need_n->index_pipe_fd - 1 >= 0) {
        if (is_str_redirector(mysh_need->command_split[mysh_need->nb_field\
        - 1][0]) != OK) {
            close(fd_need_n->pipe_fd[fd_need_n->index_pipe_fd - 1][0]);
            close(fd_need_n->pipe_fd[fd_need_n->index_pipe_fd - 1][1]);
        }
    }
}

void generate_pipe(mysh_t *mysh_need, fd_need_t *fd_need_n)
{
    if (mysh_need->command_split[mysh_need->nb_field + 1] != NULL) {
        if (is_str_redirector(mysh_need->command_split[mysh_need->nb_field + 1]\
            [0]) != OK) {
            pipe(fd_need_n->pipe_fd[fd_need_n->index_pipe_fd]);
        }
    }
}

int launch_command(mysh_t *mysh_need, fd_need_t *fd_need_n)
{
    int action_built_in = 1;

    generate_pipe(mysh_need,fd_need_n);
    if (mysh_need->nb_field - 1 >= 0)
        action_built_in = file_function(mysh_need, fd_need_n);
    if (action_built_in != OK)
        action_built_in = built_in_function(mysh_need, fd_need_n);
    if (action_built_in != OK)
        binary_function(mysh_need, fd_need_n);
    if (mysh_need->command_split[mysh_need->nb_field + 1] != NULL) {
        if (is_str_redirector(mysh_need->command_split\
        [mysh_need->nb_field + 1][0]) != OK) {
            close_pipe_function(mysh_need, fd_need_n);
            fd_need_n->index_pipe_fd += 1;
        }
    }
    return OK;
}

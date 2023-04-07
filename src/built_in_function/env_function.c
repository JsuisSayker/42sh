/*
** EPITECH PROJECT, 2023
** B-PSU-200-BDX-2-1-minishell1-tom.mendy
** File description:
** env_function
*/

#include "mysh.h"

int child_env_function(mysh_t *mysh_need, fd_need_t *fd_need_n)
{
    if (mysh_need->command_split[mysh_need->nb_field + 1] != NULL)
        redirector_after_cmd(mysh_need, fd_need_n);
    if (mysh_need->nb_field - 1 >= 0)
        redirector_before_cmd(mysh_need, fd_need_n);
    print_arg(mysh_need->env);
    free_map(mysh_need->env);
    for (int i = 0; i < fd_need_n->nb_redirector; i += 1) {
        free(fd_need_n->pipe_fd[i]);
    }
    free(fd_need_n->pipe_fd);
    free(fd_need_n->all_pid);
    for (int i = 0; mysh_need->command_split[i] != NULL; i += 1){
        free_map(mysh_need->command_split[i]);
    }
    free(mysh_need->command_split);
    exit(0);
}

int env_function(mysh_t *mysh_need, fd_need_t *fd_need_n)
{
    if (mysh_need->env == NULL)
        return OK;

    mysh_need->pid = fork();
    if (mysh_need->pid < 0)
        return KO;
    if (mysh_need->pid == OK) {
        return child_env_function(mysh_need, fd_need_n);
    } else {
        int wstatus = 0;
        if (fd_need_n->index_pipe_fd > 0) {
            close(fd_need_n->pipe_fd[fd_need_n->index_pipe_fd - 1][0]);
            close(fd_need_n->pipe_fd[fd_need_n->index_pipe_fd - 1][1]);
        }
        waitpid(mysh_need->pid, &wstatus, 0);
        return OK;
    }
}

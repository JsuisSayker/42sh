/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** free_child
*/

#include "mysh.h"

void free_child(mysh_t *mysh_need, fd_need_t *fd_need_n)
{
    free_map(mysh_need->path_array);
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
}

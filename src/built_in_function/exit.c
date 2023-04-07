/*
** EPITECH PROJECT, 2023
** B-PSU-200-BDX-2-1-minishell1-tom.mendy
** File description:
** exit
*/

#include "mysh.h"

int exit_function(mysh_t *mysh_need, fd_need_t *fd_need_n)
{
    free_map(mysh_need->env);
    free_command_split(mysh_need->command_split);
    free(fd_need_n->pipe_fd);
    free(fd_need_n->all_pid);
    write(1, "exit\n", 5);
    exit(mysh_need->return_value);

}

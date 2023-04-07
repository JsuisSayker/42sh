/*
** EPITECH PROJECT, 2023
** ls input
** File description:
** ls_input for the minishell 1
*/

#include "minishell.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include "pipe_elem.h"

static int is_pipe(pipe_elem_t *pipe_elem, int *returned_value)
{
    pid_t *pid = malloc(sizeof(pid_t) * pipe_elem->nb_cmds);
    for (int i = 0; i < pipe_elem->nb_cmds; i++) {
        if (create_new_child(pid, i) == 84)
            return KO;
        if (pid[i] == 0) {
            redirections(i, pipe_elem->nb_cmds, pipe_elem->fd);
            return secondary_process(pipe_elem->env,
            pipe_elem->splited_by_pipe[i]);
        } else
            last_statement(i, pipe_elem, pid, returned_value);
    }
    return OK;
}

int exec_command_and_binaries(char *new_splited_str, char **env,
int *returned_value)
{
    if (my_strlen(new_splited_str) < 1)
        return OK;
    if (invalid_null(new_splited_str) == 1) {
        (*returned_value) = 1;
        return KO;
    }
    char **splited_by_pipe = spliter_by_options(new_splited_str, "|");
    int nb_cmds = my_array_length(splited_by_pipe);
    int **fd = malloc(sizeof(int *) * (nb_cmds - 1));
    pipe_elem_t pipe_elem = {.env = env, .splited_by_pipe = splited_by_pipe,
    .nb_cmds = nb_cmds, .fd = fd};
    if (nb_cmds > 1) {
        if (malloc_fd_and_create_pipe(pipe_elem.nb_cmds, fd) == 84)
            return KO;
        if (is_pipe(&pipe_elem, returned_value) == 84)
            return KO;
    } else
        one_cmd(new_splited_str, returned_value, &pipe_elem);
    free_command(splited_by_pipe);
    return OK;
}

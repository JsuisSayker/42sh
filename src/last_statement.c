/*
** EPITECH PROJECT, 2023
** last_statement
** File description:
** last_statement
*/

#include "minishell.h"
#include <sys/wait.h>
#include <unistd.h>
#include "pipe_elem.h"

void last_statement(int i, pipe_elem_t *pipe_elem, pid_t *pid,
int *returned_value)
{
    if (i > 0) {
        close(pipe_elem->fd[i - 1][0]);
        close(pipe_elem->fd[i - 1][1]);
    }
    int wait_for_status;
    if (i == pipe_elem->nb_cmds - 1) {
        waitpid(pid[i], &wait_for_status, 0);
        (*returned_value) = WEXITSTATUS(wait_for_status);
        error_handling(wait_for_status, returned_value);

    } else {
        waitpid(pid[i], &wait_for_status, WNOHANG | 0);
        (*returned_value) = WEXITSTATUS(wait_for_status);
        error_handling(wait_for_status, returned_value);

    }
}

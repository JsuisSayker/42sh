/*
** EPITECH PROJECT, 2023
** case where the command is without a pipe
** File description:
** case_without_pipe
*/

#include "minishell.h"
#include "pipe_elem.h"
#include <unistd.h>

int case_without_pipe(pipe_elem_t *pipe_elem, int *returned_value)
{
    pid_t pid = fork();
    if (pid < 0)
        return KO;
    if (pid == 0) {
        return secondary_process(pipe_elem->env,
        pipe_elem->splited_by_pipe[0]);
    } else {
        int wait_for_status;
        waitpid(pid, &wait_for_status, 0);
        (*returned_value) = WEXITSTATUS(wait_for_status);
        error_handling(wait_for_status, returned_value);
    }
    return OK;
}

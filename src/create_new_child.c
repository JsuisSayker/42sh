/*
** EPITECH PROJECT, 2023
** create_new_child
** File description:
** comd_with_pipe
*/

#include "minishell.h"
#include <sys/wait.h>
#include <unistd.h>

int create_new_child(pid_t *pid, int i)
{
    pid[i] = fork();
    if (pid[i] < 0) {
        return KO;
    }
    return OK;
}

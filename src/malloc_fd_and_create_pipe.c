/*
** EPITECH PROJECT, 2023
** malloc fd and create pipe
** File description:
** malloc_fd_and_create_pipe
*/

#include "minishell.h"
#include <stdlib.h>
#include <unistd.h>

int malloc_fd_and_create_pipe(int nb_cmds, int **fd)
{
    for (int i = 0; i < (nb_cmds - 1); i += 1) {
        fd[i] = malloc(sizeof(int) * 2);
        if (pipe(fd[i]) == -1) {
            return KO;
        }
    }
    return OK;
}

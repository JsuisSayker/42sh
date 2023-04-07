/*
** EPITECH PROJECT, 2023
** redirections of fd for pipe cmds
** File description:
** redirections
*/

#include <unistd.h>

static void close_actual_fd(int **fd, int i, int j)
{
    if (j == (i - 1)) {
        close(fd[j][0]);
        close(fd[j][1]);
    } else if (j == i) {
        close(fd[j][0]);
        close(fd[j][1]);
    } else {
        close(fd[j][0]);
        close(fd[j][1]);
    }
}

void redirections(int i, int nb_cmds, int **fd)
{
    if (i == 0) {
        dup2(fd[0][1], STDOUT_FILENO);
        close(fd[0][0]);
        close(fd[0][1]);
    } else if (i == (nb_cmds - 1)) {
        dup2(fd[nb_cmds - 2][0], STDIN_FILENO);
        close(fd[nb_cmds - 2][0]);
        close(fd[nb_cmds - 2][1]);
    } else {
        dup2(fd[i - 1][0], STDIN_FILENO);
        dup2(fd[i][1], STDOUT_FILENO);
        for (int j = 0; j < (nb_cmds - 1); j += 1) {
            close_actual_fd(fd, i, j);
        }
    }
}

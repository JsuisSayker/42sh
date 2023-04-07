/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** file_function
*/

#include "mysh.h"

int put_stdout_in_file(const char *filename, char *str)
{
    int fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
    if (fd == -1) {
        return -1;
    }
    write(fd, str, strlen(str));
    close(fd);
    return 0;
}

int append_stdout_to_file(const char *filename, char *str)
{
    int fd = open(filename, O_CREAT | O_WRONLY | O_APPEND, S_IRWXU);
    if (fd == -1) {
        return -1;
    }
    write(fd, str, strlen(str));
    close(fd);
    return 0;
}

int greater_than_function(mysh_t *mysh_need, fd_need_t *fd_need_n)
{
    if (my_str_cmp(mysh_need->command_split[mysh_need->nb_field\
    - 1][0], ">") == OK){
        return OK;
        if (mysh_need->return_value != 0)
            return OK;
        char * str = my_load_fd_in_memory(fd_need_n->pipe_fd\
        [fd_need_n->index_pipe_fd - 1][0]);
        put_stdout_in_file(mysh_need->command_split\
        [mysh_need->nb_field][0], str);
        free(str);
        close(fd_need_n->pipe_fd[fd_need_n->index_pipe_fd - 1][0]);
        close(fd_need_n->pipe_fd[fd_need_n->index_pipe_fd - 1][1]);
        return OK;
    }
    return 1;
}

int double_greater_than_function(mysh_t *mysh_need, fd_need_t *fd_need_n)
{
    if (my_str_cmp(mysh_need->command_split[mysh_need->nb_field\
    - 1][0], ">>") == OK){
        return OK;
        if (mysh_need->return_value != 0)
            return OK;
        char * str = my_load_fd_in_memory(fd_need_n->pipe_fd\
        [fd_need_n->index_pipe_fd - 1][0]);
        append_stdout_to_file(mysh_need->command_split\
        [mysh_need->nb_field][0], str);
        free(str);
        close(fd_need_n->pipe_fd[fd_need_n->index_pipe_fd - 1][0]);
        close(fd_need_n->pipe_fd[fd_need_n->index_pipe_fd - 1][1]);
        return OK;
    }
    return 1;
}

int file_function(mysh_t *mysh_need, fd_need_t *fd_need_n)
{

    if (is_str_redirector(mysh_need->command_split[mysh_need->nb_field\
        - 1][0]) != OK) {
        if (greater_than_function(mysh_need, fd_need_n) == OK)
            return OK;
        if (double_greater_than_function(mysh_need, fd_need_n) == OK)
            return OK;
    }
    return 1;
}

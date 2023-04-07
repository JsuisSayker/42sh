/*
** EPITECH PROJECT, 2023
** B-PSU-200-BDX-2-1-minishell1-tom.mendy
** File description:
** binary_function
*/

#include "mysh.h"

static void diplay_error(mysh_t *mysh_need, int wstatus)
{
    if (WTERMSIG(wstatus) == 8) {
        mysh_need->return_value += 8;
        write(2, "Floating exception", 18);
    }
    if (WTERMSIG(wstatus) == SIGSEGV) {
        mysh_need->return_value += 11;
        write(2, "Segmentation fault", 18);
    }
    if (WCOREDUMP(wstatus) == 128) {
        mysh_need->return_value += 128;
        write(2, " (core dumped)", 14);
    }
    if (WTERMSIG(wstatus) > 0)
        write(2, "\n", 1);
}

int is_split_in_command(mysh_t *mysh_need)
{
    for (int i = mysh_need->nb_field; mysh_need->command_split[i] != NULL;
    i += 1){
        if (mysh_need->command_split[i][0][0] == '|'){
            return 1;
        }
    }
    return 0;
}

static int parent_child_function(mysh_t *mysh_need, fd_need_t *fd_need_n)
{
    if (mysh_need->pid == OK) {
        return child_function(mysh_need, fd_need_n);
    } else {
        int wstatus = 0;
        if (fd_need_n->index_pipe_fd > 0) {
            close(fd_need_n->pipe_fd[fd_need_n->index_pipe_fd - 1][0]);
            close(fd_need_n->pipe_fd[fd_need_n->index_pipe_fd - 1][1]);
        }
        if (is_split_in_command(mysh_need) == 0)
            waitpid(mysh_need->pid, &wstatus, WUNTRACED);
        else
            waitpid(mysh_need->pid, &wstatus, WUNTRACED | WNOHANG);
        free_map(mysh_need->path_array);
        mysh_need->return_value = WEXITSTATUS(wstatus);
        diplay_error(mysh_need, wstatus);
        return OK;
    }
}

int binary_function(mysh_t *mysh_need, fd_need_t *fd_need_n)
{
    if (my_map_len(mysh_need->command_split[mysh_need->nb_field]) <= 0)
        return OK;
    if (mysh_need->command_split[mysh_need->nb_field] == NULL)
        return KO;
    char *path = get_var_env(mysh_need->env, "PATH=");
    if (path == NULL)
        return KO;
    mysh_need->path_array = spliter(path, ":");
    free(path);
    if (add_cmd_to_path(mysh_need->path_array, (mysh_need->command_split\
    [mysh_need->nb_field])[0]) == KO)
        return KO;
    mysh_need->pid = fork();
    if (mysh_need->pid < 0)
        return KO;
    parent_child_function(mysh_need, fd_need_n);
    return OK;
}

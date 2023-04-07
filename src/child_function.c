/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** child_function
*/

#include "mysh.h"

static void replace_with_home(mysh_t *mysh_need, int i)
{
    if (my_str_cmp_begin(mysh_need->command_split[mysh_need->\
    nb_field][i], "~") == OK) {
        char *path_with_home = add_home_to_directory(
            mysh_need->command_split[mysh_need->nb_field][i],
            mysh_need->env);
        free(mysh_need->command_split[mysh_need->nb_field][i]);
        mysh_need->command_split[mysh_need->nb_field][i] =
        malloc(sizeof(char) * (my_str_len(path_with_home) + 1));
        mysh_need->command_split[mysh_need->nb_field][i][0] = '\0';
        my_str_cat(mysh_need->command_split[mysh_need->nb_field][i],
        path_with_home);
        free(path_with_home);
    }
}

static int display_error_child_command(char * str)
{
    write(2, str, my_str_len(str));
    int fd = open(str, O_RDONLY);
    if (fd == -1)
        write(2, ": Command not found.\n", 21);
    else {
        write(2, ": Permission denied.\n", 21);
        close(fd);
    }
    return OK;
}

int child_function(mysh_t *mysh_need, fd_need_t *fd_need_n)
{
    for (int i = 0; mysh_need->command_split[mysh_need->nb_field][i]
    != NULL; i += 1)
        replace_with_home(mysh_need, i);
    if (mysh_need->command_split[mysh_need->nb_field + 1] != NULL)
        redirector_after_cmd(mysh_need, fd_need_n);
    if (mysh_need->nb_field - 1 >= 0)
        redirector_before_cmd(mysh_need, fd_need_n);
    execve(mysh_need->command_split[mysh_need->nb_field][0],
    mysh_need->command_split[mysh_need->nb_field], mysh_need->env);
    if (!(mysh_need->command_split[mysh_need->nb_field][0][0] == '.'
    && mysh_need->command_split[mysh_need->nb_field][0][1] == '/')) {
        for (int i = 0; mysh_need->path_array[i] != NULL; i += 1) {
            execve(mysh_need->path_array[i], mysh_need->\
            command_split[mysh_need->nb_field], mysh_need->env);
        }
    }
    display_error_child_command(mysh_need->command_split[mysh_need->nb_field]\
    [0]);
    free_child(mysh_need, fd_need_n);
    exit(1);
}

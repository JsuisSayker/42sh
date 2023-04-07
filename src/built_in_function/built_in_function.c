/*
** EPITECH PROJECT, 2023
** B-PSU-200-BDX-2-1-minishell1-tom.mendy
** File description:
** built_in_function
*/

#include "mysh.h"

int is_cmd_a_built_in(mysh_t *mysh_need)
{
    char *built_in_str[] = {"cd", "setenv", "unsetenv", "env",NULL};
    for (int i = 0; built_in_str[i] != NULL; i += 1){
        if (is_cmd(mysh_need->command_split[mysh_need->nb_field][0],\
        built_in_str[i]) == OK)
            return true;
    }
    return false;
}

int built_in_function(mysh_t *mysh_need, fd_need_t *fd_need_n)
{
    if (mysh_need->command_split[mysh_need->nb_field] == NULL)
        return 0;

    if (my_map_len(mysh_need->command_split[mysh_need->nb_field]) == 0)
        return 0;
    if (is_cmd(mysh_need->command_split[mysh_need->nb_field][0], "exit") == OK)
        return exit_function(mysh_need, fd_need_n);
    if (is_cmd(mysh_need->command_split[mysh_need->nb_field][0], "cd") == OK)
        return change_directory(mysh_need);
    if (is_cmd(mysh_need->command_split[mysh_need->nb_field][0], "setenv")
    == OK)
        return setenv_function(mysh_need, fd_need_n);
    if (is_cmd(mysh_need->command_split[mysh_need->nb_field][0], "unsetenv")
    == OK)
        return unsetenv_function(&(mysh_need->env),
        mysh_need->command_split[mysh_need->nb_field]);
    if (is_cmd(mysh_need->command_split[mysh_need->nb_field][0], "env") == OK)
        return env_function(mysh_need, fd_need_n);
    return 1;
}

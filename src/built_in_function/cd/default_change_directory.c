/*
** EPITECH PROJECT, 2023
** B-PSU-200-BDX-2-1-minishell1-tom.mendy
** File description:
** default_change_directory
*/

#include "mysh.h"

int fail_default_change_directory(mysh_t *mysh_need)
{
    if (str_contain_char(mysh_need->command_split[mysh_need->nb_field][1],
    '-') == 1){
        write(2, "Usage: cd [-plvn][-|<dir>].\n", 28);
        mysh_need->return_value = 1;
        return 0;
    }
    if (display_too_many_argument(mysh_need->command_split[mysh_need->\
        nb_field]) == 1) {
        write(2, mysh_need->command_split[mysh_need->nb_field][1],
        my_str_len(mysh_need->command_split[mysh_need->nb_field][1]));
        write(2, ": Not a directory.\n", 19);
    }
    mysh_need->return_value = 1;
    return 0;
}

int default_change_directory(mysh_t *mysh_need)
{
    if (chdir(mysh_need->command_split[mysh_need->nb_field][1]) == -1) {
        fail_default_change_directory(mysh_need);
        return 0;
    }
    char *pwd = get_var_env(mysh_need->env, "PWD=");
    switch_var_env(mysh_need->env, "OLDPWD=", pwd);
    char *new_pwd = pwd_function();
    switch_var_env(mysh_need->env, "PWD=", new_pwd);
    free(pwd);
    free(new_pwd);
    return 0;
}

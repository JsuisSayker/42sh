/*
** EPITECH PROJECT, 2023
** B-PSU-200-BDX-2-1-minishell1-tom.mendy
** File description:
** previous_change_directory
*/

#include "mysh.h"

int previous_change_directory(mysh_t *mysh_need)
{
    if (my_str_cmp(mysh_need->command_split[mysh_need->nb_field][1], "-")
    == OK) {
        char *pwd = get_var_env(mysh_need->env, "PWD=");
        char *oldpwd = get_var_env(mysh_need->env, "OLDPWD=");
        if (oldpwd == NULL){
            free(pwd);
            write(2, ": No such file or directory.\n", 29);
            return 0;
        }
        int return_cd = chdir(oldpwd);
        display_error(mysh_need->command_split[mysh_need->nb_field], return_cd);
        if (return_cd == -1)
            mysh_need->return_value = 1;
        switch_var_env(mysh_need->env, "PWD=", oldpwd);
        switch_var_env(mysh_need->env, "OLDPWD=", pwd);
        free(pwd);
        free(oldpwd);
        return 0;
    }
    return 1;
}

/*
** EPITECH PROJECT, 2023
** B-PSU-200-BDX-2-1-minishell1-tom.mendy
** File description:
** home_change_directory
*/

#include "mysh.h"

int home_change_directory(mysh_t *mysh_need)
{
    if (my_str_cmp_begin(mysh_need->command_split[mysh_need->nb_field][1],
    "~") == OK || my_map_len(mysh_need->command_split[mysh_need->nb_field])
    == 1) {
        char *pwd = get_var_env(mysh_need->env, "PWD=");
        char *path_with_home = add_home_to_directory(mysh_need->\
        str_split[1], mysh_need->env);
        int return_cd = chdir(path_with_home);
        display_error(mysh_need->command_split[mysh_need->nb_field], return_cd);
        if (return_cd == -1)
            mysh_need->return_value = 1;
        switch_var_env(mysh_need->env, "OLDPWD=", pwd);
        switch_var_env(mysh_need->env, "PWD=", path_with_home);
        free(path_with_home);
        free(pwd);
        return 0;
    }
    return 1;
}

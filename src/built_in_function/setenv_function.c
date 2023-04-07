/*
** EPITECH PROJECT, 2023
** B-PSU-200-BDX-2-1-minishell1-tom.mendy
** File description:
** setenv_function
*/

#include "mysh.h"

int add_to_env(char ***env, char **str_split)
{
    char **new_env = malloc(sizeof(char *) * (my_map_len((*env)) + 2));
    char *var_value = add_equal(str_split[1]);
    int i = 0;
    for (; (*env)[i] != NULL; i += 1) {
        new_env[i] = (*env)[i];
    }
    free((*env));
    int len_value = my_str_len(str_split[2]);
    if (len_value == -1)
        len_value = 0;
    new_env[i] = malloc(sizeof(char) * (my_str_len(var_value) +
    len_value + 1));
    new_env[i][0] = '\0';
    my_str_cat(new_env[i], var_value);
    my_str_cat(new_env[i], str_split[2]);
    free(var_value);
    new_env[i + 1] = NULL;
    (*env) = new_env;
    return 0;
}

int str_containe_alpha_numeric_and_delimiter(char *str, char delimiter)
{
    for (int i = 0; str[i] != '\0'; i += 1){
        if (!(my_is_num(str[i]) || my_is_alpha(str[i]) || str[i] == delimiter))
            return 1;
    }
    return 0;
}

int setenv_function_sub(char ***env, char **str_split)
{
    char *var_value = add_equal(str_split[1]);
    int is_in_env = 0;
    if (my_map_len(str_split) == 2)
        is_in_env = switch_var_env((*env), var_value, "");
    if (my_map_len(str_split) == 3)
        is_in_env = switch_var_env((*env), var_value, str_split[2]);
    int str_ok = str_containe_alpha_numeric_and_delimiter(str_split[1], '_');
    if (is_in_env == 1 && str_ok == OK)
        add_to_env(env, str_split);
    if (str_ok != OK)
        write(2,
        "setenv: Variable name must contain alphanumeric characters.\n", 60);
    free(var_value);
    return OK;
}

int setenv_function(mysh_t *mysh_need, fd_need_t *fd_need_n)
{
    if (mysh_need->env == NULL)
        return OK;
    if (mysh_need->command_split[mysh_need->nb_field][1] == NULL)
        return env_function(mysh_need, fd_need_n);
    if (my_map_len(mysh_need->command_split[mysh_need->nb_field]) != 3 &&
    my_map_len(mysh_need->command_split[mysh_need->nb_field]) != 2) {
        write(2, "setenv: Too many arguments\n", 27);
        return OK;
    }
    setenv_function_sub(&(mysh_need->env), mysh_need->command_split\
    [mysh_need->nb_field]);
    return OK;
}

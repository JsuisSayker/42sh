/*
** EPITECH PROJECT, 2023
** Minishell2
** File description:
** function_build
*/


#include <unistd.h>

#include "macro.h"
#include "proto.h"
#include "struct.h"
#include "proto_lib.h"

static int function_build_sub(base_minishell_t *base,
char **tab_command, int len_tab)
{
    if ((len_tab = my_tablen(tab_command)) > 1)
        return OK;
    else{
        if (print_env(base->env) != OK)
            base->return_value = 1;
    }
    return KO;
}

static int function_build_ter(base_minishell_t *base, char **tab_command)
{
    if (my_strncmp("!", tab_command[0], 3) == OK){
        char *tmp_pwd = my_strcat(base->pwd, "/.history.txt");
        if (display_file(tmp_pwd) == KO)
            base->return_value = 1;
        free(tmp_pwd);
        return OK;
    }
    if (my_strncmp("echo", tab_command[0], 4) == OK){
        if (echo_command(base, tab_command) != OK)
            base->return_value = 1;
        return OK;
    }
    return KO;
}

int function_build(base_minishell_t *base, char **tab_command)
{
    int len_tab = 0;
    if (my_strncmp("setenv", tab_command[0], 6) == OK){
        if (function_build_sub(base, tab_command, len_tab) != OK)
            base->return_value = 1;
        return OK;
    }
    if (my_strncmp("env", tab_command[0], 3) == OK){
        if (print_env(base->env) != OK)
            base->return_value = 1;
        return OK;
    }
    if (function_build_ter(base, tab_command) == OK)
        return OK;
    return KO;
}

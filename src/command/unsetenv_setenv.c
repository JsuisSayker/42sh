/*
** EPITECH PROJECT, 2023
** Minishell1
** File description:
** unsetenv
*/

#include <unistd.h>

#include "proto.h"
#include "macro.h"
#include "struct.h"
#include "proto_lib.h"

int unsetenv_reprogramming(base_minishell_t *base, char *str)
{
    if (base == NULL || str == NULL)
        return KO;
    char **dest = reduce_tab(base->env, str);
    free_tab_char(base->env);
    base->env = take_env(dest);
    if (base->env == NULL)
        return KO;
    free_tab_char(dest);
    return OK;
}

int setenv_reprogramming(base_minishell_t *base, char *variable,
char *value)
{
    if (base == NULL || variable == NULL)
        return KO;
    char **dest = enlarge_tab(base->env, variable, value);
    if (dest == NULL)
        return KO;
    free_tab_char(base->env);
    base->env = take_env(dest);
    if (base->env == NULL)
        return KO;
    free_tab_char(dest);
    return OK;
}

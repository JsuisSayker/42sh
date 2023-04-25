/*
** EPITECH PROJECT, 2023
** Minishell1
** File description:
** execute_command
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <sys/wait.h>

#include "proto.h"
#include "macro.h"
#include "struct.h"
#include "proto_lib.h"

static void execution(base_minishell_t *base, need_tab_t *need_tab, char **tab)
{
    execve(tab[0], tab, base->env);
    if (tab[0][0] != '.' && tab[0][1] != '/'){
        for (int i = 0; base->path[i] != NULL; i += 1){
            char *command = string_command(base->path[i], tab[0]);
            execve(command, tab, base->env);
            free(command);
        }
    }
    write(2, tab[0], my_strlen(tab[0]));
    write(2, ": Command not found.\n", 21);
    if (base->yes_or_not == 1)
        free_tab_int(need_tab);
    free_all(base, need_tab);
}

static int command_execute(base_minishell_t *base, need_tab_t *need_tab,
char **tab)
{
    if (base == NULL || need_tab == NULL)
        return KO;
    duplicate_fonction(base, need_tab);
    if (base->yes_or_not == 1){
        if (fonction_build(base, need_tab, tab) == OK){
            free_tab_int(need_tab);
            free_all(base, need_tab);
            exit(0);
        }
    }
    execution(base, need_tab, tab);
    exit(1);
}

int command(base_minishell_t *base, need_tab_t *need_tab, char **tab)
{
    if (base == NULL || need_tab == NULL)
        return KO;
    pid_t pid = fork();
    if (pid < 0)
        return KO;
    if (pid == 0){
        return command_execute(base, need_tab, tab);
    } else {
        int value = 0;
        child_display(base, need_tab ,pid, value);
        return OK;
    }
    return OK;
}

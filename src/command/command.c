/*
** EPITECH PROJECT, 2023
** Minishell1
** File description:
** execute_command
*/

#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <sys/wait.h>
#include <stdbool.h>

#include "proto.h"
#include "macro.h"
#include "struct.h"
#include "proto_lib.h"

void display_error_command_bad_binary(base_minishell_t *base, need_tab_t
*need_tab, char * cmd)
{
    fprintf(stderr,"%s: %s. Wrong Architecture.\n", cmd, strerror(errno));
    if (base->yes_or_not == 1)
        free_tab_int(need_tab);
    free_all(base, need_tab);
    exit(1);
}

void execution(base_minishell_t *base, need_tab_t *need_tab, char **tab)
{
    errno = 0;
    execve(tab[0], tab, base->env);
    bool search_in_path_cmd = false;
    check_cmd_with_slash(&search_in_path_cmd, tab);
    if (errno == ENOEXEC)
        display_error_command_bad_binary(base, need_tab, tab[0]);
    if (search_in_path_cmd == false) {
        for (int i = 0; base->path[i] != NULL; i += 1) {
            char *command = string_command(base->path[i], tab[0]);
            execve(command, tab, base->env);
            free(command);
        }
    }
    print_error_and_free(tab, base, need_tab);
    if (errno == 8)
        exit(126);
    exit(1);
}

static int command_execute(base_minishell_t *base, need_tab_t *need_tab,
char **tab)
{
    if (base == NULL || need_tab == NULL)
        return KO;
    duplicate_function(base, need_tab);
    if (need_tab->redirect_arg == 1){
        if (left_redirector(base, need_tab, tab) != OK){
            free_all(base, need_tab);
            free_tab_char(tab);
            exit(1);
        }
    }
    if (base->yes_or_not == 1){
        if (function_build(base, tab) == OK){
            free_tab_int(need_tab);
            free_all(base, need_tab);
            free_tab_char(tab);
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

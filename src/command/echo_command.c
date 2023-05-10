/*
** EPITECH PROJECT, 2023
** Minishell_two
** File description:
** echo_command
*/

#include <unistd.h>
#include <stdio.h>

#include "macro.h"
#include "struct.h"
#include "proto_lib.h"

static int check_flag(char **command, int *flag)
{
    if (command == NULL)
        return KO;
    for (int i = 0; command[i] != NULL; i ++) {
        if (my_strncmp("-n", command[i], 2) == OK){
            *flag = 1;
        }
    }
    return OK;
}

static int echo_command_ter(char **command, int tab_len, int i)
{
    if (command == NULL)
        return KO;
    if (i < tab_len - 1)
        if (write(1, " ", 1) == KO)
            return KO;
    return OK;
}

static int oifozehguzeihfgzo(int multiple, int i, int i_begin, char **command)
{
    int len_str = 0;
    int tab_len = my_tablen(command);

    if ((len_str = my_strlen(command[i])) == KO)
        return KO;
    if (multiple == 1 && i == i_begin) {
        if (write(1, &(command[i][1]), len_str - 1) == KO)
            return KO;
    }
    if (multiple == 1 && i == tab_len - 1) {
        if (write(1, command[i], len_str - 1) == KO)
            return KO;
    }
    if (!((multiple == 1 && i == tab_len - 1) ||
    (multiple == 1 && i == i_begin))) {
        if (write(1, command[i], len_str) == KO)
            return KO;
    }
    return 0;
}

static int echo_command_sub(char **command, int tab_len, int flag, int i)
{
    int multiple = 0;
    int i_begin = i;

    if (command == NULL)
        return KO;
    return
    if (tab_len - i != 1)
        multiple = 1;
    for (; command[i] != NULL; i ++) {
        if (oifozehguzeihfgzo(multiple, i, i_begin, command) == KO)
            return KO;
        if (echo_command_ter(command, tab_len, i) != OK)
            return KO;
    }
    if (flag == 0)
        if (write(1, "\n", 1) == KO)
            return KO;
    return OK;
}

int echo_command(base_minishell_t *base, char **command)
{
    int flag = 0;
    int tab_len = 0;
    if (base == NULL || command == NULL)
        return KO;
    if ((tab_len = my_tablen(command)) == KO)
        return KO;
    if (check_flag(command, &flag) != OK)
        return KO;
    if (flag == 1){
        if (echo_command_sub(command, tab_len, flag, 2) == KO)
            return KO;
        return OK;
    }
    if (echo_command_sub(command, tab_len, flag, 1) != OK)
        return KO;
    return OK;
}

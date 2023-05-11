/*
** EPITECH PROJECT, 2023
** Minishell1
** File description:
** take_entry
*/

#include <unistd.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "macro.h"
#include "proto.h"
#include "struct.h"
#include "proto_lib.h"

static int modif_str(char *entry)
{
    int i = 0;

    if (entry == NULL)
        return -1;
    for (i = 0; entry[i] != '\0' && entry[i] != '\n'; i += 1) {
        if (entry[i] == '\t')
            entry[i] = ' ';
    }
    entry[i] = '\0';
    return 0;
}

static int check_space(char *entry)
{
    int len_str = my_strlen(entry);
    int count = 0;

    for (int i = 0; entry[i] != '\0'; i += 1) {
        if (entry[i] == ' ')
            count += 1;
    }
    if (count == len_str)
        return KO;
    return OK;
}

static int take_entry_sub(base_minishell_t *base, char *entry,
int *nbr_parameter, int *restart)
{
    if (my_strlen(entry) == 0 || check_space(entry) != OK){
        free(entry);
        *restart = 1;
        return OK;
    } else {
        *nbr_parameter = take_parameter(entry);
        if (*nbr_parameter == 0)
            replace_alias_with_command(base, &entry);
        if (entry_w_parameter_or_not(base, entry, nbr_parameter) != OK) {
            free_tab_char(base->command);
            *restart = 1;
        }
        if (check_for_backticks(base) != OK)
            *restart = 1;
        if (*nbr_parameter != 0 && *restart == 0)
            replace_alias_with_parameter(base);
    }
    free(entry);
    return OK;
}

int append_command_to_history(base_minishell_t *base, char * str)
{
    if (str == NULL)
        return KO;
    char *tmp_pwd = my_strcat(base->pwd, "/.history.txt");
    if (append_cmd_to_history(tmp_pwd, str) == KO)
        return KO;
    free(tmp_pwd);
    return OK;
}

int take_entry(base_minishell_t *base, int *restart,
int *nbr_parameter)
{
    *restart = 0;
    char *entry = NULL;
    size_t len = 0;
    ssize_t nread;
    if ((nread = getline(&entry, &len, stdin)) == KO) {
        free(entry);
        return KO;
    }
    if (entry[my_strlen(entry) - 1] == '\n')
        entry[my_strlen(entry) - 1] = '\0';
    if (append_command_to_history(base, entry) == KO)
        return KO;
    modif_str(entry);
    if (take_entry_sub(base, entry, nbr_parameter, restart) == KO)
        return KO;
    return OK;
}

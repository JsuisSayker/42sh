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

#include "macro.h"
#include "proto.h"
#include "struct.h"
#include "proto_lib.h"

static void *modif_str(char *entry)
{
    if (entry == NULL)
        return NULL;
    int i = 0;
    for (i = 0; entry[i] != '\0' && entry[i] != '\n'; i += 1){
        if (entry[i] == '\t')
            entry[i] = ' ';
    }
    entry[i] = '\0';
}

static int check_space(char *entry)
{
    int len_str = my_strlen(entry);
    int count = 0;
    for (int i = 0; entry[i] != '\0'; i += 1){
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
        modif_str(entry);
        *nbr_parameter = take_parameter(entry);
        if (entry_w_parameter_or_not(base, entry, nbr_parameter) != OK)
            *restart = 1;
    }
    return OK;
}

int take_entry(base_minishell_t *base, char **env, int *restart,
int *nbr_parameter)
{
    *restart = 0;
    char *entry = NULL;
    size_t len = 0;
    ssize_t nread;
    if ((nread = getline(&entry, &len, stdin)) == KO)
        return KO;
    if (append_str_to_file(".save/history.txt", entry) == KO)
        return KO;
    if (take_entry_sub(base, entry, nbr_parameter, restart) == KO)
        return KO;
    free(entry);
    return OK;
}

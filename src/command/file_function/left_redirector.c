/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** left_redirector
*/

#include <unistd.h>
#include <string.h>

#include "proto.h"
#include "macro.h"
#include "proto_lib.h"

static int end_or_continue(char *entry, char *str_stop)
{
    char *clean_entry = NULL;
    if (!entry || !str_stop)
        return KO;
    if ((clean_entry = clean_str(entry)) == NULL)
        return KO;
    if (strcmp(str_stop, clean_entry) == OK){
            free(entry);
            free(clean_entry);
            return OK;
    }
    free(clean_entry);
    return KO;
}

static int getline_db_left_redirector(base_minishell_t *base,
need_tab_t *need_tab, char *str_stop)
{
    char *entry = NULL;
    size_t len = 0;
    ssize_t nread;
    if (!base || !need_tab || !str_stop)
        return KO;
    if (write(1, "? ", 2) == KO)
        return KO;
    while ((nread = getline(&entry, &len, stdin)) != KO) {
        if (end_or_continue(entry, str_stop) == OK){
            return OK;
        }
        if (append_str_to_file(".db_left_redirector", entry) == KO){
            printf("pqpp\n");
            return KO;
        }
        if (write(1, "? ", 2) == KO)
            return KO;
    }
    return OK;
}

int double_left_redirector(base_minishell_t *base, need_tab_t *need_tab)
{
    char *str_stop = NULL;
    if (!base || !need_tab)
        return KO;
    if ((str_stop = clean_str(base->p_command[need_tab->tab_pos_y]\
    [need_tab->tab_pos_x + 2])) == NULL)
        return KO;
    if (getline_db_left_redirector(base, need_tab, str_stop) != OK)
        return KO;
    free(str_stop);
    return OK;
}

int left_redirector(base_minishell_t *base, need_tab_t *need_tab,
char **tab_command)
{
    if (!base || !need_tab || !tab_command)
        return KO;
    if (strcmp("<", base->p_command[need_tab->tab_pos_y]\
    [need_tab->tab_pos_x + 1]) == OK){
        if (single_left_redirector(base, need_tab, tab_command) != OK)
            return KO;
        return OK;
    }
    if (strcmp("<<", base->p_command[need_tab->tab_pos_y]\
    [need_tab->tab_pos_x + 1]) == OK){
        if (double_left_redirector_child(base, need_tab, ".db_left_redirector",\
        tab_command) == KO)
            return KO;
        return OK;
    }
    return OK;
}

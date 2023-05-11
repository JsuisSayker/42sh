/*
** EPITECH PROJECT, 2023
** print_error_and_free.c
** File description:
** print_error_and_free
*/

#include "proto.h"
#include "macro.h"

void print_error_and_free(char **tab, base_minishell_t *base,
need_tab_t *need_tab)
{
    display_error_command(tab[0]);
    if (base->yes_or_not == 1)
        free_tab_int(need_tab);
    free_all(base, need_tab);
}

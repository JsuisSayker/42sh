/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** check_for_backticks
*/

#include <unistd.h>

#include "struct.h"
#include "macro.h"
#include "proto.h"

static void check_for_backticks_in_str(char *str, int *count_backticks)
{
    for (int index_str = 0; str[index_str] != '\0'; index_str += 1) {
        if (str[index_str] == '`')
            *count_backticks += 1;
    }
}

int check_for_backticks(base_minishell_t *base)
{
    int count_backticks = 0;
    for (int index = 0; base->command[index] != NULL; index += 1) {
        check_for_backticks_in_str(base->command[index], &count_backticks);
    }
    if (count_backticks % 2 != 0) {
        write(1, "Unmatched '`'.\n", 15);
        base->return_value = 1;
        free_tab_char(base->command);
        return KO;
    }
    return OK;
}

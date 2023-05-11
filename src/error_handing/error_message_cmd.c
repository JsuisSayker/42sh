/*
** EPITECH PROJECT, 2023
** Minishell2
** File description:
** error_message_cmd
*/

#include <unistd.h>

#include "proto.h"
#include "proto_lib.h"
#include "struct.h"

int error_and_free_message_cmd(base_minishell_t *base, char **tab)
{
    write(2, tab[0], my_strlen(tab[0]));
    write(2, ": Command not found.\n", 21);
    free_tab_char(tab);
    free_tab_char(base->env);
    free_tab_char(base->path);
    return 0;
}

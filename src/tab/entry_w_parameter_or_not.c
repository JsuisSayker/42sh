/*
** EPITECH PROJECT, 2023
** Minishell2
** File description:
** entry_w_parameter_or_not
*/

#include <unistd.h>

#include "proto.h"
#include "macro.h"
#include "struct.h"
#include "proto_lib.h"

static int entry_w_parameter(base_minishell_t *base, char *entry)
{
    int i;
    int tab_len;
    int nbr_parameter_str = 0;
    if (base == NULL || entry == NULL)
        return KO;
    base->command = my_splitstr(entry, ';');
    if (check_parameter_and_modif_tab(base) != OK)
        return KO;
    tab_len = my_tablen(base->command);
    base->p_command = malloc(sizeof(char **) * (tab_len + 1));
    base->p_command[tab_len] = NULL;
    for (i = 0; i != tab_len; i += 1){
        nbr_parameter_str = count_parameter(base->command[i]);
        if ((base->p_command[i] = my_complexspliter(base->command[i], "|<>",
        nbr_parameter_str)) == NULL)
            return KO;
    }
    return OK;
}

int entry_w_parameter_or_not(base_minishell_t *base, char *entry,
int *nbr_parameter)
{
    if (base == NULL || entry == NULL)
        return KO;
    if (*nbr_parameter == 0){
        if ((base->command = my_splitstr(entry, ' ')) == NULL)
            return KO;
        return OK;
    }else {
        if (entry_w_parameter(base, entry) != OK){
            base->return_value = 1;
            return KO;
        }
    }
    return OK;
}

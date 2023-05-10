/*
** EPITECH PROJECT, 2023
** Minishell2
** File description:
** error_message_for_redirector
*/

#include <unistd.h>

#include "macro.h"
#include "struct.h"
#include "struct_args_for_entry.h"

static int error_message_parameter_sub(base_minishell_t *base, args_s_t *args)
{
    if (!args || !base)
        return KO;
    if (args->ambigous_output == 1){
        if (write(2, "Ambiguous output redirect.\n", 27) == -1)
            return 1;
        base->return_value = 1;
        return KO;
    }
    if (args->invalide == 1){
        if (write(2, "Invalid null command.\n", 22) == -1)
            return 1;
        base->return_value = 1;
        return KO;
    }
    return OK;
}

int error_message_parameter(base_minishell_t *base, args_s_t *args)
{
    if (args->missing == 1){
        if (write(2, "Missing name for redirect.\n", 27) == -1)
            return 1;
        base->return_value = 1;
        return KO;
    }
    if (args->ambigous_input == 1){
        if (write(2, "Ambiguous input redirect.\n", 26) == -1)
            return 1;
        base->return_value = 1;
        return KO;
    }
    if (error_message_parameter_sub(base, args) == KO)
        return KO;
    return OK;
}

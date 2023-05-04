/*
** EPITECH PROJECT, 2023
** Minishell2
** File description:
** error_message_for_redirector
*/

#include <unistd.h>

#include "macro.h"
#include "struct_args_for_entry.h"

int error_message_redirector(args_s_t *args)
{
    if (args->multiple == 1){
        if (write(2, "Ambiguous output redirect.\n", 27) == -1)
            return 1;
        return 1;
    }
    if (args->after != 1){
        if (write(2, "Missing name for redirect.\n", 27) == -1)
            return 1;
        return 1;
    }
    if (args->before != 1){
        if (write(2, "Invalid null command.\n", 22) == -1)
            return 1;
        return 1;
    }
    return OK;
}

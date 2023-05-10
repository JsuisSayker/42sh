/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** replace_alias_with_parameter
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

int replace_alias_with_parameter(base_minishell_t *base)
{
    if (base == NULL)
        return OK;
    for (int i = 0; base->p_command[i] != NULL; i += 1){
        for (int j = 0; base->p_command[i][j] != NULL; j += 1){
            replace_alias_with_command(base, &(base->p_command[i][j]));
        }
    }
    return OK;
}

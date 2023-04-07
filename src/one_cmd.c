/*
** EPITECH PROJECT, 2023
** one cmd
** File description:
** one_cmd
*/

#include "minishell.h"
#include "pipe_elem.h"

int one_cmd(char *new_splited_str, int *returned_value,
pipe_elem_t *pipe_elem)
{
    if (invalid_null(new_splited_str) == 1) {
        (*returned_value) = 1;
        return KO;
    }
    if (case_without_pipe(&(*pipe_elem), returned_value) == 84)
        return KO;
    return OK;
}

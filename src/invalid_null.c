/*
** EPITECH PROJECT, 2023
** invalid_null
** File description:
** invalid_null
*/

#include <stdbool.h>
#include <unistd.h>
#include "minishell.h"

int invalid_null(char *new_splited_str)
{
    if (is_in_str(new_splited_str) == true &&
    (clean_start_str(new_splited_str) == false ||
    (clean_end_str(new_splited_str) == false))) {
        write(2, "Invalid null command.\n", 23);
        return 1;
    }
    return OK;
}

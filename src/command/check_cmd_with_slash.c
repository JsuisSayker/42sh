/*
** EPITECH PROJECT, 2023
** check_cmd_with_slash
** File description:
** check_cmd_with_slash
*/

#include <stdbool.h>
#include <stddef.h>

#include "macro.h"

void check_cmd_with_slash(bool *search_in_path_cmd, char **tab)
{
    for (int i = 0; tab[0][i] != '\0'; i += 1) {
        if (tab[0][i] == '/') {
            (*search_in_path_cmd) = true;
        }
    }
}

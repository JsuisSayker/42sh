/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** generate_malloc_str_from_str
*/

#include <stdlib.h>
#include "my_str.h"

char *generate_malloc_str_from_str(char const *const str)
{
    if (str == NULL)
        return NULL;
    char *str_malloc = malloc(sizeof(char) * (my_str_len(str) + 1));
    if (str_malloc == NULL)
        return NULL;
    if (my_str_cpy(str_malloc, str) == -1) {
        free(str_malloc);
        return NULL;
    }
    return str_malloc;
}

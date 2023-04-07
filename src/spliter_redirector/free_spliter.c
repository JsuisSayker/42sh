/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** free_spliter
*/

#include <stdbool.h>
#include <stdlib.h>

#include "my_str.h"

static int free_spliter_sub(char **array, char **redirector, int const i)
{
    int is_redirector = false;
    for (int j = 0; redirector[j] != NULL; j += 1) {
        if (my_str_cmp(array[i], redirector[j]) == 0)
            is_redirector = true;
    }
    if (is_redirector == false)
        free(array[i]);
    return 0;
}

int free_spliter(char **array, char **redirector)
{
    for (int i = 0; array[i] != NULL; i += 1) {
        free_spliter_sub(array, redirector, i);
    }
    free(array);
    return 0;
}

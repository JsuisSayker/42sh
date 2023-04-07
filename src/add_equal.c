/*
** EPITECH PROJECT, 2023
** B-PSU-200-BDX-2-1-minishell1-tom.mendy
** File description:
** add_equal
*/

#include "mysh.h"

char *add_equal(char *str)
{
    if (str == NULL)
        return NULL;
    char *equal = generate_malloc_str_from_str("=");
    if (equal == NULL)
        return NULL;
    char *var_value = malloc(sizeof(char) * (my_str_len(str) + 2));
    var_value[0] = '\0';
    my_str_cat(var_value, str);
    my_str_cat(var_value, equal);
    free(equal);
    return var_value;
}

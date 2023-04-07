/*
** EPITECH PROJECT, 2023
** verify_null_cmd
** File description:
** verify_null_cmd
*/

#include <stdbool.h>
#include "minishell.h"

int clean_start_str(char const* str)
{
    bool is_first = false;
    for (int i = 0; str[i] != '|'; i += 1) {
        if (my_char_isalpha(str[i]) == true) {
            is_first = true;
        }
    }
    return is_first;
}

int clean_end_str(char const* str)
{
    int count = 0;
    for (; str[count] != '|'; count += 1);
    bool is_first = false;
    for (int i = count; str[i] != '\0'; i += 1) {
        if (my_char_isalpha(str[i]) == true) {
            is_first = true;
        }
    }
    return is_first;
}

int is_in_str(char *str)
{
    for (int i = 0; str[i] != '\0'; i += 1) {
        if (str[i] == '|')
            return true;
    }
    return false;
}

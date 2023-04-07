/*
** EPITECH PROJECT, 2023
** count_words_in_args
** File description:
** a side function for my_str_to_word_array
*/

#include <stdbool.h>
#include <stdio.h>
#include "my_str.h"
#include "str_wa.h"

static void look_word(int i, int *count, bool *is_a_word, str_wa_t *str_wa)
{
    if (my_char_isalpha(str_wa->str[i]) == true ||
    is_a_sep(str_wa->str[i], str_wa->separator) == true) {
        if (!(*is_a_word)) {
            (*count) += 1;
            (*is_a_word) = true;
        }
    } else if (is_a_sep(str_wa->str[i], str_wa->separator) == false)
        (*is_a_word) = false;
}

int count_words_in_args(char *str, char *separator)
{
    str_wa_t str_wa = {.str = str, .separator = separator};
    int count = 0;
    bool is_a_word = false;
    for (int i = 0; str[i] != '\0'; i += 1) {
        look_word(i, &count, &is_a_word, &str_wa);
    }
    return count;
}

static void loook_only_words(int i, int *count, bool *is_a_word, str_wa_t
*str_wa)
{
    if (is_a_sep(str_wa->str[i], str_wa->separator) == false) {
        if (!(*is_a_word)) {
            (*count) += 1;
            (*is_a_word) = true;
        }
    } else if (is_a_sep(str_wa->str[i], str_wa->separator) == true)
        (*is_a_word) = false;
}

int count_words_options(char *str, char *separator)
{
    str_wa_t str_wa = {.str = str, .separator = separator};
    int count = 0;
    bool is_a_word = false;
    for (int i = 0; str[i] != '\0'; i += 1) {
        loook_only_words(i, &count, &is_a_word, &str_wa);
    }
    return count;
}

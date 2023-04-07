/*
** EPITECH PROJECT, 2023
** my_str_to_word_array function
** File description:
** my_str_to_word_array
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "my_str.h"

static int is_sep_in_args(char *str, char *separator,int count)
{
    if ((my_char_isalpha(str[count]) == true &&
    is_a_sep(str[count + 1], separator) == true) ||
    (is_a_sep(str[count], separator) == true &&
    my_char_isalpha(str[count + 1]) == true) ||
    (is_a_sep(str[count], separator) == true &&
    is_a_sep(str[count + 1], separator) == true))
            return true;
    return false;
}

static void increase_count_and_other_var(int *count, int *char_in_str)
{
    (*count) += 1;
    (*char_in_str) += 1;
}

char **my_str_to_word_array(char *str, char *separator)
{
    int nb_words = count_words_in_args(str, separator);
    char **array_words = malloc(sizeof(char *) * (nb_words + 1));
    int count = 0;
    int char_in_str = 0;
    for (int i = 0; i < nb_words; i += 1) {
        if (str[count] != '\0' && my_char_isalpha(str[count]) == false &&
            is_a_sep(str[count], separator) == false) {
            not_a_char_in_str(str, &count, separator);
        }
        int len_str = len_of_an_str(str, count, separator) + 1;
        array_words[i] = malloc(sizeof(char) * len_str);
        while (str[count] != '\0' && (my_char_isalpha(str[count]) == true ||
        is_sep_in_args(str, separator, count) == true)) {
            array_words[i][char_in_str] = str[count];
            increase_count_and_other_var(&count, &char_in_str);
        }
        end_of_the_word(array_words, i, &char_in_str, &count);
    }
    array_words[nb_words] = NULL;
    return array_words;
}

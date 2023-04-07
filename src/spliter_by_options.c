/*
** EPITECH PROJECT, 2023
** spliter by options
** File description:
** spliter by options
*/

#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include "minishell.h"

static int count_words_with_options(char *str, char *options)
{
    int count = count_words_options(str, options);
    if (is_a_sep(str[0], options) == true)
        return -1;
    return count;
}

static int len_str_with_option(char *str, int *counter, char *options)
{
    int count = 0;
    char delim = options[0];
    for (; str[(*counter)] != delim && str[(*counter)] != '\0';
    (*counter) += 1) {
        count += 1;
    }
    return count;
}

char **spliter_by_options(char *str, char *options)
{
    int words = count_words_with_options(str, options);
    int counter = 0;
    int starting_value = 0;
    int char_in_str = 0;
    if (words == -1)
        return NULL;
    char **splited_str = malloc(sizeof(char * ) * (words + 1));
    splited_str[words] = NULL;
    for (int i = 0; i < words; i += 1) {
        splited_str[i] = malloc(sizeof(char) * (len_str_with_option(str,
        &counter, options) + 1));
        for (int j = starting_value; str[j] != options[0] && str[j] != '\0';
        j += 1) {
            splited_str[i][char_in_str] = str[char_in_str + starting_value];
            char_in_str += 1;
        }
        end_of_the_word(splited_str, i, &char_in_str, &counter);
        starting_value = counter;
    }
    return splited_str;
}

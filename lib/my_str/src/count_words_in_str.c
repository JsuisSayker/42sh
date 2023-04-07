/*
** EPITECH PROJECT, 2023
** count a nb of words into an str
** File description:
** count_words_in_str
*/

#include <stdbool.h>
#include "my_str.h"

int count_words_in_str(char *str)
{
    int count = 0;
    for (int i = 0; str[i] != '\0'; i += 1) {
        if (str[i] == ':') {
            count += 1;
        }
    }
    return count + 1;
}

/*
** EPITECH PROJECT, 2023
** array_length
** File description:
** my_array_length
*/

#include <stddef.h>

int my_array_length(char **array)
{
    int count = 0;
    for (int i = 0; array[i] != NULL; i += 1) {
        count += 1;
    }
    return count;
}

/*
** EPITECH PROJECT, 2023
** my_str_len
** File description:
** counts and returns the number of characters found in the string
*/

#include <stdlib.h>

int my_map_len(char **map)
{
    if (map == NULL)
        return -1;
    if (*map == NULL)
        return -1;
    int i = 0;
    for (; map[i] != NULL; i += 1);
    return i;
}

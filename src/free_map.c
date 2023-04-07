/*
** EPITECH PROJECT, 2023
** create map
** File description:
** create_map
*/

#include "mysh.h"

int free_map(char **map)
{
    int i = 0;
    if (map == NULL)
        return 0;
    for (; map[i] != NULL; i += 1){
        free(map[i]);
    }
    free(map[i]);
    free(map);
    return 0;
}

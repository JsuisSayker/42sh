/*
** EPITECH PROJECT, 2023
** B-PSU-200-BDX-2-1-minishell2-marc.mendia
** File description:
** string_command
*/

#include <unistd.h>
#include <stdlib.h>

#include "macro.h"
#include "proto_lib.h"

char *string_command(char *path, char *entry)
{
    int y = 0;
    int len = (my_strlen(path) + my_strlen(entry) + 1);
    if (len == KO)
        return NULL;
    char *command = malloc(sizeof(char) * (len + 1));
    if (command == NULL)
        return NULL;
    for (int b = 0; b < my_strlen(path); y += 1) {
            command[y] = path[b];
            b += 1;
    }
    command[y] = '/';
    y += 1;
    for (int b = 0; b < my_strlen(entry); y += 1){
            command[y] = entry[b];
            b += 1;
    }
    command[len] = '\0';
    return command;
}

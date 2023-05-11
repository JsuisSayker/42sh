/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** clean_str
*/

#include <unistd.h>
#include <stdlib.h>

#include "macro.h"
#include "proto_lib.h"

static int clear_len(char *str, int len)
{
    int count = 0;
    if (!str)
        return KO;
    for (int i = 0; i < len; i ++){
        if (str[i] != ' ')
            break;
        count += 1;
    }
    for (int i = len - 1; 0 < i ; i ++){
        if (str[i] != ' ')
            break;
        count += 1;
    }
    if (str[len - 1] == '\n')
        count += 1;
    return count;
}

static char *malloc_and_copy_str(char *str, int len)
{
    int start = 0;
    char *return_str = NULL;
    if (!str)
        return NULL;
    if ((return_str = malloc(sizeof(char) * len + 1)) == NULL)
        return NULL;
    for (; str[start] != '\0'; start += 1){
        if (str[start] != ' ')
            break;
    }
    for (int i = 0; i < len; i ++){
        return_str[i] = str[start];
        start += 1;
    }
    return_str[len] = '\0';
    return return_str;
}

char *clean_str(char *str)
{
    int len = 0;
    int count = 0;
    char *return_str = NULL;
    if (!str)
        return NULL;
    if ((len = my_strlen(str)) == KO)
        return NULL;
    if ((count = clear_len(str, len)) == KO)
        return NULL;
    if ((return_str = malloc_and_copy_str(str, (len - count))) == NULL)
        return NULL;
    return return_str;
}

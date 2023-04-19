/*
** EPITECH PROJECT, 2023
** Minishell2
** File description:
** remove_of_tab
*/

#include <unistd.h>

#include "macro.h"
#include "proto.h"
#include "proto_lib.h"

static int count_src(char **src, char *str)
{
    int count = 0;
    int b = 0;
    if (src == NULL)
        return KO;
    for (int i = 0; src[i] != NULL; i += 1){
        if (b == 1 && src[i][0] == ';')
            b = 0;
        if (my_strncmp(str, src[i], 2) == OK)
            b = 1;
        if (b == 0)
            count += 1;
    }
    return count;
}

char **remove_of_tab(char **src, char *str)
{
    int len_src = 0;
    char **dest = NULL;
    int x = 0;
    int b = 0;
    if ((len_src = count_src(src, str)) == KO)
        return NULL;
    if ((dest = malloc(sizeof(char *) * (len_src + 1))) == NULL)
        return NULL;
    for (int i = 0; src[i] != NULL; i += 1){
        if (b == 1 && src[i][0] == ';')
            b = 0;
        if (my_strncmp(str, src[i], 2) == OK)
            b = 1;
        if (b == 0){
            dest[x] = my_strcpy(src[i]);
            x += 1;
        }
    }
    dest[len_src] = NULL;
    return dest;
}

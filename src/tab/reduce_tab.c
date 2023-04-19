/*
** EPITECH PROJECT, 2023
** Minishell1
** File description:
** copy_tab
*/

#include <unistd.h>

#include "macro.h"
#include "proto.h"
#include "proto_lib.h"

static int count_src(char **src, char *str, int len_str)
{
    if (src == NULL || str == NULL)
        return KO;
    int count = 0;
    int i = 0;
    for (i = 0; src[i] != NULL; i += 1){
        if (my_strncmp_spe(str, src[i], len_str) == OK &&
        src[i][len_str] == '=')
            count += 1;
    }
    return (i - count);
}

char **reduce_tab(char **src, char *str)
{
    all_str_t *all_str = malloc(sizeof(all_str_t));
    if ((all_str->len_str = my_strlen(str)) == KO)
        return NULL;
    if ((all_str->str = my_strcpy(str)) == NULL)
        return NULL;
    int len_src = count_src(src, all_str->str, all_str->len_str);
    char **dest = malloc(sizeof(char *) * (len_src + 1));
    int x = 0;
    for (int y = 0; src[y] != NULL; y += 1){
        if (my_strncmp_spe(all_str->str, src[y], all_str->len_str) == OK &&
            src[y][all_str->len_str] == '='){
            continue;
        } else {
            dest[x] = my_strcpy(src[y]);
            x += 1;
        }
    }
    dest[len_src] = NULL;
    free_str(all_str);
    return dest;
}

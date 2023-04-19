/*
** EPITECH PROJECT, 2023
** Minishell1
** File description:
** enlarge_tab
*/

#include <unistd.h>

#include "macro.h"
#include "proto.h"
#include "proto_lib.h"

static int count_src(char **src, char *str, int len_str, int *exist_or_not)
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
    if (count == 0){
        i += 1;
        *exist_or_not = 1;
    }
    return i;
}

char **enlarge_tab(char **src, char *variable, char *value)
{
    all_str_t *all_str = malloc(sizeof(all_str_t));
    if ((all_str->len_str = my_strlen(variable)) == KO)
        return NULL;
    if ((all_str->str = my_strcpy(variable)) == NULL)
        return NULL;
    char **dest = NULL;
    int exist_or_not = 0;
    int len_src = count_src(src, all_str->str, all_str->len_str, &exist_or_not);
    if (exist_or_not != 0){
        dest = add_array_to_tab(all_str, src, value, len_src);
    } else {
        dest = modif_array_to_tab(all_str, src, value, len_src);
    }
    free_str(all_str);
    return dest;
}

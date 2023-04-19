/*
** EPITECH PROJECT, 2023
** Minishell1
** File description:
** modif_tab
*/

#include <unistd.h>
#include <stdlib.h>

#include "struct.h"
#include "macro.h"
#include "proto_lib.h"

static void entry_two(char *str, char *value, int *x)
{
    if (value != NULL){
        for (int b = 0; b != my_strlen(value); *x += 1){
            str[*x] = value[b];
            b += 1;
        }
    }
}

static char *modif_tab_sub(all_str_t *all_str, char *value, int len_str)
{
    char *str = malloc(sizeof(char) * (len_str + 1));
    int x = 0;
    for (x = 0; x != my_strlen(all_str->str); x += 1)
        str[x] = all_str->str[x];
    str[x] = '=';
    x += 1;
    entry_two(str, value, &x);
    str[x] = '\0';
    return str;
}

char **add_array_to_tab(all_str_t *all_str, char **src, char *value,
int len_src)
{
    char **tab = malloc(sizeof(char *) * (len_src + 1));
    tab[len_src] = NULL;
    int entry_1 = my_strlen(all_str->str);
    int entry_2 = 0;
    int y = 0;
    int x = 0;
    if (value != NULL)
        entry_2 = my_strlen(value);
    for (y = 0; src[y] != NULL; y += 1)
        tab[y] = my_strcpy(src[y]);
    tab[y] = modif_tab_sub(all_str, value, (entry_1 + entry_2 + 1));
    return tab;
}

char **modif_array_to_tab(all_str_t *all_str, char **src, char *value,
int len_src)
{
    char **tab = malloc(sizeof(char *) * (len_src + 1));
    int entry_1 = my_strlen(all_str->str);
    int entry_2 = 0;
    int y = 0;
    if (value != NULL)
        entry_2 = my_strlen(value);
    for (y = 0; src[y] != NULL; y += 1){
        if (my_strncmp_spe(all_str->str, src[y], entry_1) == OK){
            tab[y] = modif_tab_sub(all_str, value, (entry_1 + entry_2 + 1));
        } else {
            tab[y] = my_strcpy(src[y]);
        }
    }
    tab[len_src] = NULL;
    return tab;
}

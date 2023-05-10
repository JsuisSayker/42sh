/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** tab_to_char
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include "macro.h"
#include "proto_lib.h"

static int len_of_str_in_tab(char **tab)
{
    int count = 0;
    if (!tab)
        return KO;
    for (int i = 0; tab[i] != NULL; i ++){
        if ((count = my_strlen(tab[i])) == KO)
            return KO;
    }
    return count;
}

char *tab_to_char(char **tab)
{
    char *str = NULL;
    int len_tab = 0;
    int a = 0;
    if (!tab)
        return NULL;
    if ((len_tab = len_of_str_in_tab(tab)) == KO)
        return NULL;
    for (int i = 0; i < len_tab; i += 1){
        for (int b = 0; tab[i][b] != '\0'; b ++){
            str[a] = tab[i][b];
            a += 1;
        }
        if ((i + 1) != len_tab){
            str[a] = ' ';
            a += 1;
        }
    }
    return str;
}

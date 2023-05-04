/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** alias
*/

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include "macro.h"
#include "proto.h"
#include "proto_lib.h"

static int append_alias_mutiple_cmd(FILE *fd, int width, char **tab)
{
    fprintf(fd, "%-*s (", width, tab[1]);
    for (int i = 2; tab[i] != NULL; i += 1) {
        fprintf(fd, "%s", tab[i]);
        if (tab[i + 1] != NULL)
            fprintf(fd, " ");
    }
    fprintf(fd, ")\n");
    return OK;
}

int print_table(int len_tab, FILE *fd, char **tab)
{
    int width = 8;
    int len_word = my_strlen(tab[1]);
    for (; width < len_word; width += 8);
    if (len_tab == 3)
        fprintf(fd, "%-*s %s\n", width, tab[1], tab[2]);
    else {
        append_alias_mutiple_cmd(fd, width, tab);
    }
    return 0;
}

int special_case(char **str_split_text, char **tab, FILE *fd)
{
    char **str_split_line = my_splitstr(str_split_text[0], ' ');
    if (strcmp(str_split_line[0], tab[1]) == 0) {
        print_table(my_tablen(tab), fd, tab);
        free_tab_char(str_split_line);
        return 0;
    }
    free_tab_char(str_split_line);
    if (strcmp(str_split_text[0], tab[1]) < 0) {
        fprintf(fd, "%s\n", str_split_text[0]);
        print_table(my_tablen(tab), fd, tab);
        return 0;
    }
    print_table(my_tablen(tab), fd, tab);
    fprintf(fd, "%s\n", str_split_text[0]);
    return 0;
}

int place_between_exiting_alias(char **str_split_text, int i, char **tab,
FILE *fd)
{
    if (str_split_text[i + 1] != NULL){
        if ((strcmp(str_split_text[i], tab[1]) > 0) &&
        (strcmp(str_split_text[i + 1], tab[1]) < 0)) {
            print_table(my_tablen(tab), fd, tab);
            return 1;
        }
    }
    return 0;
}

int already_exist(char *key_variable, char **tab, FILE *fd, int *is_print)
{
    if (strcmp(key_variable, tab[1]) == 0 && *is_print == 0) {
        print_table(my_tablen(tab), fd, tab);
        *is_print = 1;
    }
}

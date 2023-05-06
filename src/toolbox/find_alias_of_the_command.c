/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** find_alias_of_the_command
*/

#include <unistd.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "macro.h"
#include "proto.h"
#include "struct.h"
#include "proto_lib.h"

static char *generate_malloc_str_from_str(char const *const str)
{
    if (str == NULL)
        return NULL;
    char *str_malloc = malloc(sizeof(char) * (strlen(str) + 1));
    if (str_malloc == NULL)
        return NULL;
    strcpy(str_malloc, str);
    return str_malloc;
}

static int get_len_multiple_word(char **str_split_line)
{
    int len_multiple_word = 0;
    for (int j = 1; str_split_line[j] != NULL; j += 1) {
        len_multiple_word += strlen(str_split_line[j]);
    }
    len_multiple_word -= 2;
    len_multiple_word += my_tablen(str_split_line) - 1;
    return len_multiple_word;
}

static int append_alias_to_str_split(char **str_split_line, char **str_plit,
int len_multiple_word)
{
    strcpy(str_plit[0], &(str_split_line[1][1]));
    strcat(str_plit[0], " ");
    for (int j = 2; str_split_line[j + 1] != NULL; j += 1) {
        strcat(str_plit[0], str_split_line[j]);
        strcat(str_plit[0], " ");
    }
    strcat(str_plit[0], str_split_line[my_tablen(str_split_line) - 1]);
    str_plit[0][len_multiple_word - 1] = '\0';
    return OK;
}

int find_alias_of_the_command(char **str_split_line, char **str_plit)
{
    if (strcmp(str_plit[0], str_split_line[0]) == 0) {
        free(str_plit[0]);
        if (my_tablen(str_split_line) == 2) {
            char *str_malloc = generate_malloc_str_from_str(
            str_split_line[1]);
            str_plit[0] = str_malloc;
        } else {
            int len_multiple_word = get_len_multiple_word(str_split_line);
            str_plit[0] = malloc(sizeof(char) * (len_multiple_word + 1));
            append_alias_to_str_split(str_split_line, str_plit,
            len_multiple_word);
        }
        free_tab_char(str_split_line);
        return 1;
    }
    free_tab_char(str_split_line);
    return OK;
}

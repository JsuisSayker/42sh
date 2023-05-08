/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** replace_alias_with_command
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

static int replace_base_command(char **str_split_text, char **str_plit)
{
    if (str_split_text == NULL || str_plit == NULL)
        return KO;
    for (int i = 0; str_split_text[i] != NULL; i += 1){
        char **str_split_line = my_splitstr(str_split_text[i], ' ');
        if (str_split_line == NULL)
            return OK;
        if (find_alias_of_the_command(str_split_line, str_plit) == 1)
            return OK;
    }
    return OK;
}

static int get_len_alloc_str_split_to_str(char **str_plit)
{
    int len_malloc = 0;

    if (str_plit == NULL)
        return 0;
    for (int i = 0; str_plit[i] != NULL; i += 1){
        len_malloc += strlen(str_plit[i]) + 1;
    }
    return len_malloc;
}

static int replace_entry_with_command_alias(char **str_plit, char **entry)
{
    int len_malloc = get_len_alloc_str_split_to_str(str_plit);

    if (str_plit == NULL || entry == NULL)
        return KO;
    free((*entry));
    (*entry) = malloc(sizeof(char) * (len_malloc));
    strcpy((*entry), str_plit[0]);
    for (int i = 1; str_plit[i] != NULL; i += 1) {
        strcat((*entry), " ");
        strcat((*entry), str_plit[i]);
    }
    return OK;
}

int replace_alias_with_command(base_minishell_t *base, char **entry)
{
    if (entry == NULL)
        return KO;
    char **str_plit = NULL;
    char *tmp_pwd = my_strcat(base->pwd, "/.alias.txt");
    char *str_file_in_memory = my_load_file_in_memory(tmp_pwd);

    free(tmp_pwd);
    if (str_file_in_memory == NULL)
        return OK;
    str_plit = my_splitstr((*entry), ' ');
    char **str_split_text = my_splitstr(str_file_in_memory, '\n');
    replace_base_command(str_split_text, str_plit);
    replace_entry_with_command_alias(str_plit, entry);
    free_tab_char(str_plit);
    free(str_file_in_memory);
    free_tab_char(str_split_text);
    return OK;
}

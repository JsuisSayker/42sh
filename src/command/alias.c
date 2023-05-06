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

int filter_and_print_text(char **str_split_text, char **tab, FILE *fd)
{
    int is_print = 0;
    if (my_tablen(str_split_text) == 1)
        return special_case(str_split_text, tab, fd);
    for (int i = 0; str_split_text[i] != NULL; i += 1) {
        char **str_split_line = my_splitstr(str_split_text[i], ' ');
        if (place_between_exiting_alias(str_split_text, i, tab, fd) == 1)
            is_print = 1;
        already_exist(str_split_line[0], tab ,fd, &is_print);
        if (strcmp(str_split_text[i], tab[1]) > 0 && is_print == 0) {
            print_table(my_tablen(tab), fd, tab);
            is_print = 1;
        }
        if (strcmp(str_split_line[0], tab[1]) != 0)
            fprintf(fd, "%s\n", str_split_text[i]);
        free_tab_char(str_split_line);
    }
    if (is_print == 0)
        print_table(my_tablen(tab), fd, tab);
    return OK;
}

static int append_alias(char const *filename, char **tab)
{
    char *str_file_in_memory = my_load_file_in_memory(filename);
    if (str_file_in_memory == NULL){
        FILE *fd = fopen(filename, "w+");
        print_table(my_tablen(tab), fd, tab);
        fclose(fd);
    } else {
        FILE *fd = fopen(filename, "w+");
        char **str_split_text = my_splitstr(str_file_in_memory, '\n');
        filter_and_print_text(str_split_text, tab, fd);
        free_tab_char(str_split_text);
        fclose(fd);
    }
    free(str_file_in_memory);
    return OK;
}

int display_alias_value_in_alias_sub(char **str_split)
{
    for (int i = 1; str_split[i] != NULL; i += 1){
        write(1, str_split[i], my_strlen(str_split[i]));
        if (str_split[i + 1] != NULL)
            write(1, " ", 1);
    }
    return OK;
}

static int display_alias_value_in_alias(char *filemane, char *value)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;
    FILE *stream = fopen(filemane, "a+");

    while ((nread = getline(&line, &len, stream)) != -1) {
        char **str_split = my_splitstr(line, ' ');
        if (strcmp(str_split[0], value) == 0){
            display_alias_value_in_alias_sub(str_split);
        }
        free_tab_char(str_split);
    }
    fclose(stream);
    free(line);
    return OK;
}

int alias(base_minishell_t *base, char **tab)
{
    if (tab == NULL)
        return KO;
    char *tmp_pwd = my_strcat(base->pwd, "/.alias.txt");
    if (tmp_pwd == NULL)
        return KO;
    switch (my_tablen(tab)){
        case 1:
            display_file(tmp_pwd);
            break;
        case 2:
            display_alias_value_in_alias(tmp_pwd, tab[1]);
            break;
        default:
            append_alias(tmp_pwd, tab);
            break;
    }
    free(tmp_pwd);
    return OK;
}

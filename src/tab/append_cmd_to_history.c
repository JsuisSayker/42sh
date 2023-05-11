/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** appand_str_to_file
*/

#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include <time.h>
#include <stdio.h>
#include "macro.h"
#include "proto.h"
#include "proto_lib.h"

int create_history(char *str_file_in_memory, const char *filename,
char *str, char **str_split_hours)
{
    FILE *fd;

    if (str_file_in_memory == NULL || filename == NULL || str == NULL ||
    str_split_hours == NULL)
        return KO;
    if (str_file_in_memory == NULL){
        fd = fopen(filename, "w+");
        fprintf(fd, "%6d\t%2s:%s\t%s\n", 1, str_split_hours[0],
        str_split_hours[1], str);
        fclose(fd);
        return 0;
    }
    return 1;
}

int get_nb_cmd(char **str_split_text, char **str_split_line, int *nb_end,
int i)
{
    if (str_split_text == NULL || str_split_line == NULL || nb_end == NULL)
        return KO;
    if (str_split_text[i + 1] == NULL){
        int j = 0;
        for (; str_split_line[0][j] == ' '; j += 1);
        (*nb_end) = atoi(&(str_split_line[0][j]));
    }
    return 0;
}

int append_cmd_to_history_sub(const char *filename, char *str,
char *str_file_in_memory, char **str_split_hours)
{
    FILE *fd;
    int i = 0;
    int nb_end = 0;
    fd = fopen(filename, "w+");
    char **str_split_text = my_splitstr(str_file_in_memory, '\n');
    for (; str_split_text[i] != NULL; i += 1) {
        char **str_split_line =
        my_splitstr(str_split_text[i], '\t');
        if (strcmp(str_split_line[2], str) != 0)
            fprintf(fd, "%s\n", str_split_text[i]);
        get_nb_cmd(str_split_text, str_split_line, &nb_end, i);
        free_tab_char(str_split_line);
    }
    free_tab_char(str_split_text);
    fprintf(fd, "%6d\t%2s:%s\t%s\n", nb_end + 1, str_split_hours[0],
    str_split_hours[1], str);
    fclose(fd);
    return 0;
}

char **get_current_hour(void)
{
    char *current_time = get_actual_time();
    char **str_split_time = my_splitstr(current_time, ' ');
    char **str_split_hours = my_splitstr(str_split_time[3], ':');
    free_tab_char(str_split_time);
    return str_split_hours;
}

int append_cmd_to_history(const char *filename, char *str)
{
    char **str_split_hours = NULL;
    char *str_file_in_memory = NULL;
    if (filename == NULL || str == NULL)
        return -1;
    if (strlen(str) == 0)
        return 0;
    str_split_hours = get_current_hour();
    str_file_in_memory = my_load_file_in_memory(filename);
    int value_return = create_history(str_file_in_memory,
    filename, str, str_split_hours);
    if (value_return == 1){
        value_return = append_cmd_to_history_sub(filename, str,
        str_file_in_memory, str_split_hours);
    }
    free_tab_char(str_split_hours);
    free(str_file_in_memory);
    return value_return;
}

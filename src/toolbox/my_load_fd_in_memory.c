/*
** EPITECH PROJECT, 2023
** new_project_folder_file
** File description:
** my_load_fd_in_memory
*/

#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include "proto.h"
#include "proto_lib.h"


static void add_buffer_to_end_str_sub(char **result_str, char *buffer, int
    nb_to_copy, int len_str)
{
    for (int i = 0; i < nb_to_copy; i += 1) {
        (*result_str)[len_str + i] = buffer[i];
    }
}

static int add_str_to_end_str(char **result_str, char *buffer, int nb_to_copy)
{
    char *save_str = NULL;
    int len_str = 0;
    if ((*result_str) == NULL || buffer == NULL || nb_to_copy < 0)
        return 84;
    len_str = my_strlen((*result_str));
    save_str = my_strcpy((*result_str));
    if (save_str == NULL || len_str == -1)
        return 84;
    free((*result_str));
    (*result_str) = malloc(sizeof(char) * (len_str + nb_to_copy + 1));
    if ((*result_str) == NULL)
        return 84;
    (*result_str)[0] = '\0';
    strcat((*result_str), save_str);
    add_buffer_to_end_str_sub(result_str, buffer, nb_to_copy, len_str);
    (*result_str)[len_str + nb_to_copy] = '\0';
    free(save_str);
    return 0;
}

static int if_error_close_fd(void *function, void *value, int *fd)
{
    if (function == value) {
        return 84;
        close((*fd));
    }
    return 0;
}

static int my_load_fd_in_memory_sub(int *nread, char *buffer,\
char **result_str)
{
    if ((*nread) == -1) {
        return 84;
    }
    if (add_str_to_end_str(result_str, buffer, (*nread)) == 84) {
        return 84;
    }
    return 0;
}

char *my_load_fd_in_memory(int fd)
{
    printf("fd [%d]\n", fd);
    int nread = 1;
    int nb_byte = 100;
    char buffer[nb_byte];
    char *result_str = malloc(sizeof(char) * (1));
    result_str[0] = '\0';
    if (fd == -1 || !result_str){
        return NULL;
    }
    if (if_error_close_fd(result_str, NULL, &fd)){
        printf("Je t'emmerde hein\n");
        return NULL;
    }
    while ((nread = read(fd, buffer, nb_byte)) != 0) {
        printf("            on est nombreux !\n");
        if (my_load_fd_in_memory_sub(&nread, buffer, &result_str) == 84)
            return NULL;
        if (nread < nb_byte){
            printf("{%s}\n", result_str);
            return result_str;
        }
    }
    printf("{%s}\n", result_str);
    return result_str;
}


// static int add_str_to_end_str(char **result_str, char *buffer, int nb_to_copy)
// {
//     if ((*result_str) == NULL || buffer == NULL || nb_to_copy < 0)
//         return 84;
//     int len_str = my_strlen((*result_str));
//     if (len_str == -1)
//         len_str = 0;
//     char *save_str = malloc(sizeof(char) * (len_str + 1));
//     if (save_str == NULL)
//         return 84;
//     save_str[0] = '\0';
//     strcat(save_str, (*result_str));
//     free((*result_str));
//     (*result_str) = malloc(sizeof(char) * (len_str + nb_to_copy + 1));
//     if ((*result_str) == NULL)
//         return 84;
//     (*result_str)[0] = '\0';
//     strcat((*result_str), save_str);
//     add_buffer_to_end_str_sub(result_str, buffer, nb_to_copy, len_str);
//     (*result_str)[len_str + nb_to_copy] = '\0';
//     free(save_str);
//     return 0;
// }
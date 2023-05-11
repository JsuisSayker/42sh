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

#include "macro.h"
#include "proto.h"
#include "proto_lib.h"


static char *add_buffer_to_end_str_sub(char *result_str, char *buffer,
int nread, int len_str)
{
    if (!result_str || !buffer)
        return NULL;
    for (int x = 0; x < nread; x += 1) {
        result_str[len_str + x] = buffer[x];
    }
    return result_str;
}

static char *add_str_to_end_str(char *result_str, char *buffer, int nread)
{
    int len_str = 0;
    char *save_str = NULL;
    if (!result_str || !buffer)
        return NULL;
    if ((len_str = my_strlen(result_str)) == KO)
        return NULL;
    if ((save_str = malloc(sizeof(char) * (len_str + 1))) == NULL)
        return NULL;
    save_str[0] = '\0';
    if ((save_str = strcat(save_str, result_str)) == NULL)
        return NULL;
    free(result_str);
    if ((result_str = malloc(sizeof(char) * (len_str + nread + 1))) == NULL)
        return NULL;
    result_str[0] = '\0';
    result_str = strcat(result_str, save_str);
    result_str = add_buffer_to_end_str_sub(result_str, buffer, nread, len_str);
    result_str[len_str + nread] = '\0';
    free(save_str);
    return result_str;
}

char *my_load_fd_in_memory(int fd)
{
    int len_buffer = 100;
    char *result_str = NULL;
    char buffer[len_buffer];
    ssize_t nread = 1;
    if ((result_str = malloc(sizeof(char) * 1)) == NULL){
        close(fd);
        return NULL;
    }
    result_str[0] = '\0';
    while ((nread = read(fd, buffer, len_buffer)) > 0){
        if ((result_str = add_str_to_end_str(result_str, buffer, nread))
        == NULL){
            close(fd);
            return NULL;
        }
        if (nread < len_buffer)
            return result_str;
    }
    return result_str;
}

/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** write_in_file
*/

#include <unistd.h>
#include <string.h>
#include <fcntl.h>

#include "macro.h"

int put_stdout_in_file(const char *filename, char *str)
{
    if (!filename || !str)
        return KO;
    int fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
    if (fd == -1) {
        return -1;
    }
    write(fd, str, strlen(str));
    close(fd);
    return 0;
}

int append_stdout_to_file(const char *filename, char *str)
{
    if (!filename || !str)
        return KO;
    int fd = open(filename, O_CREAT | O_WRONLY | O_APPEND, S_IRWXU);
    if (fd == -1) {
        return -1;
    }
    write(fd, str, strlen(str));
    close(fd);
    return 0;
}

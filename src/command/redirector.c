/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** redirector
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

int overwrite_to_file(char *str, char *filename)
{
    int fd = -1;
    if (filename == NULL)
        return -1;
    fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC);
    if (fd == -1)
        return -1;
    write(fd, str, strlen(str));
    close(fd);
    return 0;
}

int write_to_file(char *str, char *filename)
{
    int fd = -1;

    if (filename == NULL)
        return -1;
    fd = open(filename, O_CREAT | O_WRONLY | O_APPEND);
    if (fd == -1)
        return -1;
    write(fd, str, strlen(str));
    close(fd);
    return 0;
}

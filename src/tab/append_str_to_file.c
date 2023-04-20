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

int append_str_to_file(const char *filename, char *str)
{
    int fd = -1;

    if (filename == NULL)
        return -1;
    fd = open(filename, O_CREAT | O_WRONLY | O_APPEND, S_IRWXU);
    if (fd == -1)
        return -1;
    write(fd, str, strlen(str));
    close(fd);
    return 0;
}

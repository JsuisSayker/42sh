/*
** EPITECH PROJECT, 2023
** is_fifo
** File description:
** verify if an echo with pipe command is used
*/

#include <stdbool.h>
#include <sys/stat.h>

int is_fifo(void)
{
    struct stat s;
    fstat(0, &s);
    if (S_ISFIFO(s.st_mode))
        return true;
    return false;
}

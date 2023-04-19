/*
** EPITECH PROJECT, 2023
** Minishell1
** File description:
** starting
*/

#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>

#include "macro.h"
#include "proto.h"
#include "proto_lib.h"

static int if_echo(void)
{
    struct stat s;
    int fd = 0;
    fstat(fd, &s);
    if (S_ISFIFO(s.st_mode))
        return KO;
    return OK;
}

int starting(void)
{
    if (if_echo() != KO){
        if (write(1, "$> ", 3) == -1)
            return KO;
        return OK;
    }
    return 1;
}

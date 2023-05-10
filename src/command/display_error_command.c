/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** display_error_command
*/

#include <errno.h>
#include <string.h>
#include <fcntl.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <sys/wait.h>

#include "proto.h"
#include "macro.h"
#include "struct.h"
#include "proto_lib.h"

static int display_with_permission(char *cmd)
{
    int fd = 0;
    if (write(2, cmd, my_strlen(cmd)) == -1)
        return 84;
    fd = open(cmd, O_RDONLY);
    if (fd == -1){
        if (write(2, ": Command not found.\n", 21) == -1)
            return 84;
    } else {
        if (write(2, ": Permission denied.\n", 21) == -1)
            return 84;
        close(fd);
    }
    return 0;
}

int display_error_command(char *cmd)
{
    if (cmd == NULL)
        return 0;
    switch (errno){
        case 2:
            if (display_with_permission(cmd) == 84)
                return 84;
            break;
        default:
            fprintf(stderr,"%s: %s\n", cmd, strerror(errno));
            break;
    }
    return 0;
}

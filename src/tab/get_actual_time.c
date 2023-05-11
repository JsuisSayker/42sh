/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** get_actual_time
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

char *get_actual_time(void)
{
    struct tm* local;
    time_t t = time(NULL);
    local = localtime(&t);
    char *current_time = asctime(local);
    return current_time;
}

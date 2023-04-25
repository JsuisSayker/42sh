/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** display_file
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int display_file(const char *filename)
{
    FILE *stream;
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;

    if (filename == NULL)
        return -1;
    stream = fopen(filename, "r");
    if (stream == NULL) {
        return 0;
    }
    while ((nread = getline(&line, &len, stream)) != -1) {
        write(1, line, nread);
    }
    free(line);
    fclose(stream);
    return 0;
}

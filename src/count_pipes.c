/*
** EPITECH PROJECT, 2023
** count_pipes
** File description:
** count pipes
*/

int count_pipes(char *buf_size)
{
    int count = 0;
    for (int i = 0; buf_size[i] != '\0'; i += 1) {
        if (buf_size[i] == '|' && buf_size[i + 1] == '|' &&
        buf_size[i + 2] == '|')
            count += 1;
    }
    return count;
}

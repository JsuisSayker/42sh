/*
** EPITECH PROJECT, 2022
** my_strcat
** File description:
** my_strcat
*/

#include <unistd.h>
#include <stdlib.h>

int my_strlen(char const *str);

char *my_strcat(char *dest, char const *src)
{
    if (src == NULL || !dest)
        return NULL;
    int len_dest = 0;
    int len_src = my_strlen(src);
    int count = 0;
    if (dest != NULL)
        len_dest = my_strlen(dest);
    if (len_dest == -1 || len_src == -1)
        return NULL;
    char *tmp = malloc(sizeof(char) * (len_dest + len_src) + 1);
    for (int i = 0; dest[i] != '\0' && dest[i] != '\n'; i += 1){
        tmp[count] = dest[i];
        count += 1;
    }
    for (int i = 0; src[i] != '\0' && src[i] != '\n'; i += 1){
        tmp[count] = src[i];
        count += 1;
    }
    tmp[count] = '\0';
    return tmp;
}

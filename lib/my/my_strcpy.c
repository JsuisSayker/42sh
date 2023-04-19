/*
** EPITECH PROJECT, 2022
** my_strcpy
** File description:
** sauvegarder un mot dans une autre variable
*/

#include <unistd.h>
#include <stdlib.h>

int my_strlen(char const *str);

char *my_strcpy(char const *src)
{
    if (src == NULL)
        return NULL;
    int count = 0;
    char *dest = NULL;
    for (count = 0; src[count] != '\0' && src[count] != '\n'; count += 1);
    dest = malloc(sizeof(char) * (count + 1));
    if (dest == NULL)
        return NULL;
    for (int i = 0; src[i] != '\0' && src[i] != '\n'; i += 1 )
        dest[i] = src[i];
    dest[count] = '\0';
    return dest;
}

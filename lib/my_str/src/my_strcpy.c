/*
** EPITECH PROJECT, 2022
** my_strcpy
** File description:
** copy a string into another
*/

int my_strlen(char const *str);

char *my_strcpy (char *dest, char const *src)
{
    int i = 0;
    while (src[i] != '\0'){
        dest[i] = src[i];
        i += 1;
    }
    if (my_strlen(dest) >= my_strlen(src)){
        dest[i] = '\0';
    }
    return dest;
}

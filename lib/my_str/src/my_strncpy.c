/*
** EPITECH PROJECT, 2022
** my_strncpy
** File description:
** display a string into another
*/

int my_strlen(char const *str);

char *my_strncpy(char *dest, char const *src, int n)
{
    int count = 0;
    while (count < n){
        dest[count] = src[count];
        count += 1;
    }
    if (n == my_strlen(src)){
        dest[count] = '\0';
    }
    return dest;
}

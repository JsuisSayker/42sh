/*
** EPITECH PROJECT, 2023
** my_putstr
** File description:
** display a string
*/

#include <unistd.h>

int my_strlen (char const *str);

int my_putstr (char const *str)
{
    write(1, str, my_strlen(str));
}

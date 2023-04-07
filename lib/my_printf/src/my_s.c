/*
** EPITECH PROJECT, 2023
** my_s
** File description:
** my_s
*/

#include <stdarg.h>

int my_putstr(const char *);

int my_s(const char *format, va_list list, int count)
{
    my_putstr(va_arg(list, const char *));
    return (count);
}

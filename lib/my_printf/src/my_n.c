/*
** EPITECH PROJECT, 2023
** flag n
** File description:
** flag n
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int my_n(const char *format, va_list list, int nb)
{
    int count = 0;
    while (format[count] != '%' && format[count + 1] != 'n'){
        count = count + 1;
    }
    va_arg(list, int *)[0] = count;
    return 0;
}

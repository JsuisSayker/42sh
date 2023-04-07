/*
** EPITECH PROJECT, 2023
** my_c
** File description:
** c flag
*/

#include <stdarg.h>

void my_putchar(char c);

int my_c(const char *flag, va_list list, int count)
{
    my_putchar(va_arg(list, int));
    return (0);
}

/*
** EPITECH PROJECT, 2023
** my_di
** File description:
** my_di
*/

#include <stdarg.h>

int my_putnbr(int nb);

int my_di(const char *flag, va_list list, int count)
{
    my_putnbr(va_arg(list, int));
    return (0);
}

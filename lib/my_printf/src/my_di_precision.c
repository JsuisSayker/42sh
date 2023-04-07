/*
** EPITECH PROJECT, 2023
** flag di
** File description:
** flag di
*/

#include <stdarg.h>
#include "my_printf.h"

int my_putnbr(int nb);

int count_nbr_precision(int nb)
{
    int count = 1;
    while (nb > 10){
        nb = nb / 10;
        count = count + 1;
    }
    return count;
}

int my_di_precision(const char *format, va_list list, int precision)
{
    int nb = va_arg(list, int);
    int count = 0;
    if (count_nbr_precision(nb) > precision){
        my_putnbr(nb);
        return 0;
    }
    while (count < precision){
        my_putchar('0');
        count = count + 1;
    }
    my_putnbr(va_arg(list, int));
    return (0);
}

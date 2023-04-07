/*
** EPITECH PROJECT, 2023
** my_x
** File description:
** my_x
*/

#include <stdarg.h>
#include "my_printf.h"

int my_put_base_x(int nb, int base)
{
    char str[] = "0123456789ABCDEF";
    if (nb > base - 1) {
        my_put_base_x(nb / base, base);
        if (str[nb % base] >= 'A' && str[nb % base] <= 'F'){
            my_putchar(str[nb % base]);
        } else {
            my_putchar(nb % base + 48);
        }
    } else {
        if (str[nb % base] >= 'A' && str[nb % base] <= 'F'){
            my_putchar(str[nb % base]);
        } else {
            my_putchar(nb % base + 48);
        }
    }
    return (0);
}

int my_upper_x(const char *format, va_list list, int nb)
{
    long int va = va_arg(list, long int);
    if (0 > va){
        va = va * -1;
    }
    my_put_base_x(va, 16);
}

/*
** EPITECH PROJECT, 2023
** flags p
** File description:
** displays pointeur in hexa
*/

#include <stdarg.h>
#include "my_printf.h"

void my_putchar (char c);

int my_putnbr_base(int nb, int base)
{
    char *str = "0123456789ABCDEF";
    if (nb > base - 1) {
        my_putnbr_base(nb / base, base);
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

int my_p(const char *format, va_list list, int nb)
{
    long int va = va_arg(list, long int);
    my_putstr("0x");
    if (0 > va){
        va = va * -1;
    }
    my_putnbr_base(va, 16);
}

/*
** EPITECH PROJECT, 2023
** precision
** File description:
** flags with precision
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include "my_printf.h"
#include "struct.h"

int my_strlen(const char *str);

int my_point(const char *format, va_list list, int nb)
{
    int nbr = 0;
    int t = 1;
    while (format[nb] <= '9' & format[nb] >= '0'){
        nbr = (format[nb] - '0') * t + nbr;
        t = t * 10;
        nb = nb + 1;
    }
    if (format[nb] == 'd' && format[nb] == 'i'){
        my_di_precision(format, list, nbr);
    }
    if (format[nb] == 'f'){
        my_f_precision(format, list, nbr);
    }
    if (format[nb] == 'e'){
        my_e_precision(format, list, nbr);
    }
}

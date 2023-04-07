/*
** EPITECH PROJECT, 2023
** flag e
** File description:
** The double argument is rounded and converted in the style [-]d.ddde±dd
*/

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "my_printf.h"

void my_putchar (char c);
int my_putstr (char const *str);
char *my_strcat(char *dest, char const *src);
int my_strlen (char const *str);

char *scientifique(int count, char signe)
{
    char *str = malloc(sizeof(char) * (1 + signe + 2 + 1));
    str[0] = 'e';
    str[1] = signe;
    if (count < 10){
        str[2] = '0';
        str[3] = count + '0';
    } else {
        str[2] = (count / 10) % 10;
        str[3] = count % 10;
    }
    return str;
}

char *float_to_str(char *str, double va_double, int precision)
{
    int i = va_double;
    str[0] = '0';
    str[1] = i + 48;
    va_double = va_double - i;
    int count = 2;
    int nb = 0;
    int t = 10;
    int p = precision + count;
    str[count] = '.';
    while (count != p){
        va_double = va_double * t;
        nb = va_double;
        count = count + 1;
        str[count] = nb + 48;
        va_double = va_double - nb;
    }
    return str;
}

int my_e(const char *format, va_list list, int nb)
{
    double va_double = va_arg(list, double);
    char signe = '+';
    int count = 0;
    if (va_double < 1){
        while (va_double < 1){
            va_double = va_double * 10;
            count = count + 1;
        }
        signe = '-';
    } else {
        while (va_double > 10){
            va_double = va_double / 10;
            count = count + 1;
        }
    }
    char *str = malloc(sizeof(char) * (2 + 1 + 6 + 4 + 1));
    int i = va_double;
    my_putstr(my_strcat(rounded(float_to_str(str, va_double, 6),
    va_double - i), scientifique(count, signe)));
}

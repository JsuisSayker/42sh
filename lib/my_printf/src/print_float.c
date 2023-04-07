/*
** EPITECH PROJECT, 2023
** print float
** File description:
** print float with precision
*/
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "my_printf.h"

void my_putchar (char c);
int my_putstr (char const *str);
int my_strlen (char const *str);
char *decale_str(char *str);
int while_five(double va_double);
char *rounded_nbr(char *str, int count);
char *rounded_float(char *str);
char *rounded(char *str, double va_double);


char *float_in_str(char *str, double fl)
{
    int count = my_strlen(str);
    int nb = 0;
    int t = 10;
    int p = 6 + count;
    str[count] = '.';
    while (count != p){
        fl = fl * t;
        nb = fl;
        count = count + 1;
        str[count] = nb + 48;
        fl = fl - nb;
    }
    return str;
}

char *int_str(long int i, char *str, int count)
{
    str[0] = '0';
    int t = 10;
    int c = 1;
    if (i % 10 == 0){
        str[c] = '0';
    }
    while (c < count + 1){
        str[c] = (i % 10) + 48;
        c = c + 1;
    }
    return str;
}

int my_f(const char *format, va_list list, int nb)
{
    double va_double = va_arg(list, double);
    long int i = va_double;
    int count = 0;
    int point = 0;
    while (i > 0){
        count = count + 1;
        i = i / 10;
    }
    char *str = malloc(sizeof(char) * (count + 1 + 6 + point + 2));
    str = int_str(i = va_double, str, count);
    my_putstr(rounded(float_in_str(str, va_double - i), va_double - i));
}

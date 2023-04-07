/*
** EPITECH PROJECT, 2023
** rounded
** File description:
** rounded a double
*/

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "my_printf.h"

int my_strlen (char const *str);
char *decale_str(char *str);

int while_five(double va_double)
{
    va_double = va_double * 10;
    int i = va_double;
    while (i == 5){
        va_double = va_double - i;
        va_double = va_double * 10;
        i = va_double;
    }
    if (i < 5){
        return 0;
    } else {
        return 1;
    }
}

char *rounded_nbr(char *str, int count)
{
    if (str[count] < '9'){
        str[count] = str[count] + 1;
        return decale_str(str);
    } else {
        while (str[count] == '9'){
            str[count] = '0';
            count = count - 1;
        }
        if (count != 0){
            str[count] = str[count] + 1;
            return decale_str(str);
        } else {
            str[count] = '1';
            return str;
        }
    }
}

char *rounded_float(char *str)
{
    int count = my_strlen(str) - 1;
    if (str[count] != '9'){
        str[count] = str[count] + 1;
        return decale_str(str);
    } else {
        while (str[count] == '9'){
            str[count] = '0';
            count = count - 1;
        }
        if (str[count] == '.'){
            return rounded_nbr(str, count - 1);
        }
        str[count] = str[count] + 1;
        return decale_str(str);
    }
}

double double_precision(double va_double)
{
    int count = 0;
    int c = 0;
    while (count < 6){
        va_double = va_double * 10;
        count = count + 1;
        c = va_double;
        va_double = va_double - c;
    }
    return va_double;
}

char *rounded(char *str, double va_double)
{
    int i = 0;
    int count = 0;
    i = double_precision(va_double) * 10;
    if (i < 5){
        return decale_str(str);
    }
    if (i == 5){
        count = while_five(double_precision(va_double));
        if (count == 1){
            return rounded_float(str);
        } else {
            return decale_str(str);
        }
    }
    if (9 >= i && i > 5){
        return rounded_float(str);
    }
}

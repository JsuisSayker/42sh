/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** my_printf
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include "my_printf.h"
#include "struct.h"

int my_strlen(const char *str);

const struct flags_container FLAGS[] = {
    {'d', &my_di},
    {'i', &my_di},
    {'c', &my_c},
    {'s', &my_s},
    {'%', &pourcentage},
    {'o', &my_octal},
    {'b', &my_b},
    {'X', &my_upper_x},
    {'u', &my_u},
    {'n', &my_n},
    {'x', &my_x},
    {'f', &my_f},
    {'e', &my_e},
    {'p', &my_p},
    {'0', NULL}
    };

static int search_flags(const char *format, va_list list, int count)
{
    int i = 0;
    while (FLAGS[i].c != '0') {
        if (format[count] == FLAGS[i].c) {
            int value = FLAGS[i].flags("%", list, count);
        }
        i += 1;
    }
    return (0);
}

int my_printf(const char *format, ...)
{
    int count = 0;
    va_list list;
    va_start(list, format);
    while (format[count] != '\0'){
        if (format[count] == '%'){
            count += 1;
            search_flags(format, list, count);
        } else {
            my_putchar(format[count]);
        }
        count += 1;
    }
    va_end(list);
    return (count);
}

/*
** EPITECH PROJECT, 2023
** shitf
** File description:
** shift a elt in a string
*/

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "my_printf.h"

char *decale_str(char *str)
{
    int i = 0;
    int j = 1;
    while (str[i] != '\0'){
        str[i] = str[j];
        i = i + 1;
        j = j + 1;
    }
    return str;
}

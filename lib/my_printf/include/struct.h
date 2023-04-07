/*
** EPITECH PROJECT, 2023
** my_printf.h
** File description:
** struct definition
*/

#include <stdarg.h>

#ifndef TEST_H_
    #define TEST_H_
    typedef struct flags_container{
        char c;
        int (*flags)(const char *, va_list, int);
    } flags_t;

#endif /* !TEST_H_ */

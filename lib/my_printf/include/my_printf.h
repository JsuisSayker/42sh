/*
** EPITECH PROJECT, 2023
** my
** File description:
** my
*/

#include <stdarg.h>

#ifndef PROTO_T_
    #define PROTO_T_
    int my_putstr (char const *str);
    int my_c(const char *flag, va_list list,  int count);
    int my_di(const char *flag, va_list list, int count);
    int my_p(const char *format, va_list list, int nb);
    int pourcentage(const char *format, va_list list, int count);
    int my_octal(const char *format, va_list list, int nb);
    int my_s(const char *format, va_list list, int count);
    int my_b(const char *format, va_list list, int nb);
    int my_f(const char *format, va_list list, int nb);
    int my_x(const char *format, va_list list, int count);
    int my_n(const char *format, va_list list, int nb);
    int my_upper_s(const char *format, va_list list, int nb);
    void my_putchar(char c);
    int my_putnbr(int nb);
    char *decale_str(char *str);
    int while_five(double va_double);
    char *rounded_nbr(char *str, int count);
    char *rounded_float(char *str);
    char *rounded(char *str, double va_double);
    int my_strlen (char const *str);
    char *my_strcat(char *dest, char const *src);
    int my_e(const char *format, va_list list, int nb);
    int my_upper_x(const char *format, va_list list, int nb);
    int my_u(const char *format, va_list list, int nb);
    char *rounded_precision(char *str, double va_double, int precision);
    double double_p(double va_double, int precision);
    char *rounded_float_precision(char *str);
    char *rounded_nbr_precision(char *str, int count);
    int while_five_precision(double va_double);
    int my_di_precision(const char *format, va_list list, int precision);
    int my_point(const char *format, va_list list, int nb);
    int my_e_precision(const char *format, va_list list, int nb);
    int my_f_precision(const char *format, va_list list, int nb);
#endif /* !PROTO_T_ */

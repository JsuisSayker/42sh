/*
** EPITECH PROJECT, 2023
** flags S
** File description:
** dispaly no printable in ocal base
*/

#include <stdarg.h>

void my_putchar(char c);

int my_octal(int nb);

static int my_putzero(char c)
{
    if (c < 10){
        my_putchar('0');
        my_putchar('0');
    }
    if (c < 100 && c >= 10){
        my_putchar('0');
    }
    return 0;
}

int my_upper_s(const char *format, va_list list, int nb)
{
    int count = 0;
    char *va = va_arg(list, char *);
    while (va[count] != '\0'){
        if (va[count] <= 32 || va[count] >= 127){
            my_putchar('\\');
            my_putzero(va[count]);
            my_octal(va[count]);
        } else {
            my_putchar(va[count]);
        }
        count = count + 1;
    }
}

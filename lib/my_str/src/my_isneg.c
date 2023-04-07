/*
** EPITECH PROJECT, 2022
** my_isneg
** File description:
** return 'N' or 'P'
*/

#include <unistd.h>

int my_isneg (int n)
{
    if (n < 0){
        write(1, "N", 1);
    } else {
        write(1, "P", 1);
    }
    return 0;
}

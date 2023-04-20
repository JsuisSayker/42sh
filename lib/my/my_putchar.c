/*
** EPITECH PROJECT, 2022
** fek
** File description:
** f;e;lz
*/

#include <unistd.h>

#include "macro.h"

int my_putchar(char c)
{
    if (write (1, &c, 1) == KO)
        return KO;
}

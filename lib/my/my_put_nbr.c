/*
** EPITECH PROJECT, 2022
** my_putnbr
** File description:
** permet d'afficher des nombre
*/

#include "my.h"
#include "macro.h"

int my_put_nbr(int nb)
{
    if (nb < 0) {
        if (my_putchar('-') == KO)
            return KO;
        nb = nb * -1;
    }
    if (nb > 9){
        if (my_put_nbr(nb / 10) == KO)
            return KO;
        if (my_putchar(nb % 10 + 48) == KO)
            return KO;
    } else {
        if (my_putchar(nb + 48) == KO)
            return KO;
    }
    return OK;
}

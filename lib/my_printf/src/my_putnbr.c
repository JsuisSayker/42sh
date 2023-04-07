/*
** EPITECH PROJECT, 2023
** my_put_nbr
** File description:
** display the number given in param
*/

void my_putchar(char c);

int my_putnbr(int nb)
{
    int count = 0;
    if (nb < 0){
        my_putchar('-');
        nb *= -1;
    }
    if (nb > 9) {
        my_putnbr(nb / 10);
        my_putchar(nb % 10 + 48);
    } else {
        my_putchar(nb + 48);
    }
    if (nb > 2147483647 || nb < -2147483648) {
        return (0);
    }
    return (0);
}

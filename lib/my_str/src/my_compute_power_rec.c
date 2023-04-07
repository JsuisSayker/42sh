/*
** EPITECH PROJECT, 2022
** my_compute_power_rec
** File description:
** recursive for a power of a number
*/

int my_compute_power_rec (int nb, int p)
{
    int count = 0;
    if (p == 0){
        return (1);
    }
    if (p < 0){
        return (0);
    }
    count = nb * my_compute_power_rec(nb, p - 1);
    if (count > 2147483647){
        return (0);
    }
    if (count < -2147483648){
        return (0);
    }
    return (count);
}

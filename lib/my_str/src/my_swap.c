/*
** EPITECH PROJECT, 2022
** my_swap
** File description:
** swap two number
*/

int my_swap (int *a, int *b)
{
    int c;
    c = *a;
    *a = *b;
    *b = c;
}

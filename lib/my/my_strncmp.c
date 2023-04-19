/*
** EPITECH PROJECT, 2022
** my_strncmp
** File description:
** a Faire
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int count = 0;
    while ((s1[count] != '\0' || s2[count] != '\0')) {
        if (s1[count] - s2[count] != 0)
            return -1;
        count += 1;
    }
    if (n > count || n < count)
        return 1;
    return 0;
}

int my_strncmp_spe(char const *s1, char const *s2, int n)
{
    int count = 0;
    while ((s1[count] != '\0' || s2[count] != '\0') && n > count) {
        if (s1[count] - s2[count] != 0)
            return -1;
        count += 1;
    }
    return 0;
}

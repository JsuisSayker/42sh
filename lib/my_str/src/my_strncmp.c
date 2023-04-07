/*
** EPITECH PROJECT, 2022
** my_strncmp
** File description:
** strncmp
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    for (int count = 0; s1[count] != '\0' || s2[count] != '\0' && n > count;
    count += 1) {
        if (s1[count] - s2[count] != 0) {
            return 1;
        }
    }
    return 0;
}

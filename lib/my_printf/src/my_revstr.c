/*
** EPITECH PROJECT, 2023
** my_revstr
** File description:
** reverse strings
*/

int my_strlen(char *str);

char *my_revstr(char *str)
{
    char tmp = 'a';
    int count = my_strlen(str) + 1;
    int mid_len = count / 2;
    for (int i = 0; i < mid_len; i += 1){
        tmp = str[i];
        str[i] = str[count - i - 2];
        str[count - i - 2] = tmp;
    }
    return str;
}

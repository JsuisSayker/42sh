/*
** EPITECH PROJECT, 2022
** my_strupcase
** File description:
** strupcase
*/

char *my_strupcase(char *str)
{
    int count = 0;
    while (str[count] != '\0'){
        if (str[count] > 96 && str[count] < 123){
            str[count] = str[count] - 32;
        }
        count += 1;
    }
    return (str);
}

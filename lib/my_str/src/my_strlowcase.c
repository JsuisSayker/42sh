/*
** EPITECH PROJECT, 2022
** my_strlowcase
** File description:
** strlowcase
*/

char *my_strlowcase(char *str)
{
    int count = 0;
    while (str[count] != '\0'){
        if (str[count] > 64 && str[count] < 91){
            str[count] = str[count] + 32;
        }
        count += 1;
    }
    return (str);
}

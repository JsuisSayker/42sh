/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** str_only_contain_str
*/

static int str_only_contain_str_sub(char *str, char *delimiter, int i)
{
    int is_in_str = 1;
    for (int j = 0; delimiter[j] != '\0'; j += 1) {
        if (str[i] == delimiter[j])
            is_in_str = 0;
    }
    if (is_in_str == 1)
        return 1;
    return 0;
}

int str_only_contain_str(char *str, char *delimiter)
{
    for (int i = 0; str[i] != '\0'; i += 1) {
        if (str_only_contain_str_sub(str, delimiter, i) == 1)
            return 1;
    }
    return 0;
}

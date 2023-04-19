/*
** EPITECH PROJECT, 2023
** proto_lib
** File description:
** proto_lib
*/

#ifndef PROTO_LIB_H

    #define PROTO_LIB_H

    char **my_tabcpy(char **src);
    char *my_strcpy(char const *src);
    char *my_strcat(char *dest, char const *src);
    char **my_str_to_word_array(char const *str);
    char **my_splitstr(char const *str, int separator);
    char **my_complexspliter(char const *str, char *separator,
    int nbr_parameter);

    int my_tablen(char **tab);
    int my_strncmp(char const *s1, char const *s2, int n);
    int my_strncmp_spe(char const *s1, char const *s2, int n);
    int my_str_isalpha(char const *str);
    int my_str_isalpha_num(char const *str, int i);
    int my_all_str_isalpha_num(char const *str);
    int my_strlen(char const *str);

#endif /* PROTO_LIB_H */

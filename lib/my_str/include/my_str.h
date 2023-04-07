/*
** EPITECH PROJECT, 2023
** my_str lib functions header
** File description:
** my_str
*/

#ifndef STR_LIB
    #define STR_LIB
    int my_compute_power_rec (int nb, int p);
    int my_isneg (int n);
    int my_strcmp(char const *s1, char const *s2);
    int my_strncmp(char const *s1, char const *s2, int n);
    char *my_strcpy (char *dest, char const *src);
    int my_strlen (char const *str);
    char *my_strlowcase(char *str);
    char *my_strncpy(char *dest, char const *src, int n);
    char *my_strstr(char *str, char const *to_find);
    char *my_strupcase(char *str);
    int my_swap (int *a, int *b);
    int my_char_isalpha(const char c);
    int count_words_in_str(char *str);
    int len_of_an_str(char *str, int count, char *separator);
    char **my_str_to_word_array(char *str, char *separator);
    void not_a_char_in_str(char *str, int *count, char *separator);
    int is_a_sep(char c, char *separator);
    int count_words_in_args(char *str, char *separator);
    void end_of_the_word(char **array_words, int i, int *char_in_str,
    int *count);
    int my_str_is_alphanum(const char *str);
#endif /* !STR_LIB */

/*
** EPITECH PROJECT, 2023
** B-PSU-200-BDX-2-1-minishell1-tom.mendy
** File description:
** spliter
*/

#ifndef SPLITER_H_
    #define SPLITER_H_
    typedef struct spliter{
        int i;
        int num_words;
        char *str;
        int str_length;
        int word_index;
        int word_start;
        int spe_char;
    }spliter_t;
    void add_word(char **word_array, spliter_t *bag);
    void init_pliter_structure(spliter_t *bag, char *str, char const *const
    delimiter);
    char **generate_tab(spliter_t *bag);
    void clean_array(char **word_array, spliter_t bag, int const l,
    int const m);
    int change_begin_str(spliter_t *bag);
    void replace_delimiter(spliter_t *bag, int const i, char const *const
    delimiter);
#endif /* !SPLITER_H_ */

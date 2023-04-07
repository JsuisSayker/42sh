/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** spliter_redirector
*/

#ifndef SPLITER_REDIRECTOR_H_
    #define SPLITER_REDIRECTOR_H_
    typedef struct count_nb_cell_of_array_s{
        int nb_cells;
        int redirector_find;
    }count_nb_cell_of_array_t;
    typedef struct spliter_redirector_s{
        char **array_split;
        char **redirector;
        char *str;
    }spliter_redirector_t;
    int count_nb_cell_of_array(char const *const str, char **redirector);
    int free_spliter(char **array, char **redirector);
    char **spliter_redirector(char *str, char **redirector);
    int is_redirector(char const *s1, char const *s2);
#endif /* !SPLITER_REDIRECTOR_H_ */

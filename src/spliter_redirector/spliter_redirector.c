/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** spliter_redirector
*/

#include "mysh.h"
#include "spliter_redirector.h"
#include <stdlib.h>

static int put_end_str(spliter_redirector_t *spliter_redirector_n,
    int array_index, int i)
{
    if (spliter_redirector_n->str[i + 1] == '\0') {
        i += 1;
        spliter_redirector_n->array_split[array_index] =
        malloc(sizeof(char) * (i + 1));
        my_str_n_cpy(spliter_redirector_n->array_split[array_index],
        spliter_redirector_n->str, i);
        spliter_redirector_n->array_split[array_index][i] = '\0';
        return 1;
    }
    return 0;
}

static int put_word_and_delimiter(spliter_redirector_t *spliter_redirector_n,
    int *array_index, int *i)
{
    for (int j = 0; spliter_redirector_n->redirector[j] != NULL; j += 1) {
        if (is_redirector(&(spliter_redirector_n->str[(*i) + 1]),
            spliter_redirector_n->redirector[j]) == 0) {
            (*i) += 1;
            spliter_redirector_n->array_split[(*array_index)] =
            malloc(sizeof(char) * ((*i) + 1));
            my_str_n_cpy(spliter_redirector_n->array_split[(*array_index)],
            spliter_redirector_n->str, (*i));
            spliter_redirector_n->array_split[(*array_index)][(*i)] = '\0';
            (*array_index) += 1;
            spliter_redirector_n->array_split[(*array_index)] =
            spliter_redirector_n->redirector[j];
            (*array_index) += 1;
            (*i) += my_str_len(spliter_redirector_n->redirector[j]);
            spliter_redirector_n->str = &(spliter_redirector_n->str[(*i)]);
            (*i) = 0;
            return 0;
        }
    }
    return 0;
}

static int spliter_redirector_sub(spliter_redirector_t *spliter_redirector_n)
{
    int i = 0;
    int array_index = 0;
    for (; spliter_redirector_n->str[i] != '\0'; i += 1) {
        if (put_end_str(spliter_redirector_n, array_index, i) == 1)
            return 0;
        put_word_and_delimiter(spliter_redirector_n, &array_index, &i);
    }
    return 0;
}

char **spliter_redirector(char *str, char **redirector)
{
    if (str == NULL || redirector == NULL)
        return NULL;
    if (*str == '\0' || *redirector == NULL)
        return NULL;
    int nb_cells = count_nb_cell_of_array(str, redirector);
    if (nb_cells == 0)
        return NULL;
    char **array_split = malloc(sizeof(char *) * (nb_cells + 1));
    spliter_redirector_t spliter_redirector_n = { .str = str, .redirector =
    redirector, .array_split = array_split };
    if (array_split == NULL)
        return NULL;
    spliter_redirector_sub(&spliter_redirector_n);
    array_split[nb_cells] = NULL;
    return array_split;
}

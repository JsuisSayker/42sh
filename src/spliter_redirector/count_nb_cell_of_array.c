/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** count_nb_cell_of_array
*/

#include "my_str.h"
#include "mysh.h"
#include <stdbool.h>
#include <stdlib.h>
#include "spliter_redirector.h"

int count_nb_cell_of_array_sub(char const *const str, char **redirector,
    count_nb_cell_of_array_t *count_nb_cell_of_array_n, int *i)
{
    if (count_nb_cell_of_array_n->redirector_find == true) {
        count_nb_cell_of_array_n->redirector_find = false;
        count_nb_cell_of_array_n->nb_cells += 1;
    }
    for (int j = 0; redirector[j] != NULL; j += 1) {
        if (is_redirector(&(str[(*i)]), redirector[j]) == 0) {
            count_nb_cell_of_array_n->redirector_find = true;
            (*i) += my_str_len(redirector[j]) - 1;
            count_nb_cell_of_array_n->nb_cells += 1;
            return 0;
        }
    }
    return 0;
}

int count_nb_cell_of_array(char const *const str, char **redirector)
{
    if (str == NULL || redirector == NULL)
        return 0;
    count_nb_cell_of_array_t count_nb_cell_of_array_n = {.nb_cells = 1,
    .redirector_find = false};
    for (int i = 0; str[i] != '\0'; i += 1) {
        count_nb_cell_of_array_sub(str, redirector,
        &count_nb_cell_of_array_n, &i);
    }
    return count_nb_cell_of_array_n.nb_cells;
}

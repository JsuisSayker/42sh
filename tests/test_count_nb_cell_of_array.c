/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** test_count_nb_cell_of_array
*/

#include "mysh.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(count_nb_cell_of_array, basic_test){
    char *redirector[] = { ";", "|", ">>", ">", "<<", "<", NULL };
    char str[] = "ls -la|grep Makefile";
    int nb_value = count_nb_cell_of_array(str, redirector);
    cr_assert_eq(nb_value, 3);
}

Test(count_nb_cell_of_array, NULL_str){
    char *redirector[] = { ";", "|", ">>", ">", "<<", "<", NULL };
    int nb_value = count_nb_cell_of_array(NULL, redirector);
    cr_assert_eq(nb_value, 0);
}

Test(count_nb_cell_of_array, NULL_redirector){
    char str[] = "ls -la|grep Makefile";
    int nb_value = count_nb_cell_of_array(str, NULL);
    cr_assert_eq(nb_value, 0);
}

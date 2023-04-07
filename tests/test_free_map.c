/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** test_free_map
*/

#include "mysh.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(free_map, basic_test){
    char path[] = "/usr/bin:/bin";
    char **path_array = spliter(path, ":");
    free_map(path_array);
}

Test(free_map, rigor){
    free_map(NULL);
}

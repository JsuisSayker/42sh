/*
** EPITECH PROJECT, 2023
** new_project_folder_file
** File description:
** test
*/

#include "mysh.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(add_cmd_to_path, basic_test){
    char path[] = "/usr/bin:/bin";
    char **path_array = spliter(path, ":");
    cr_assert_eq(add_cmd_to_path(path_array, "ls"), 0);
    cr_assert_str_eq(path_array[0], "/usr/bin/ls");
    cr_assert_str_eq(path_array[1], "/bin/ls");
    cr_assert_eq(path_array[2], NULL);
}

Test(add_cmd_to_path, test_no_in_env){
    char path[] = "/usr/bin:/bin";
    char **path_array = spliter(path, ":");
    add_cmd_to_path(path_array, "ls");
    cr_assert_str_eq(path_array[0], "/usr/bin/ls");
    cr_assert_str_eq(path_array[1], "/bin/ls");
    cr_assert_eq(path_array[2], NULL);
}

Test(add_cmd_to_path, NULL_path_array){
    cr_assert_eq(add_cmd_to_path(NULL, "ls"), 84);
}

Test(add_cmd_to_path, NULL_cmd){
    char path[] = "/usr/bin:/bin";
    char **path_array = spliter(path, ":");
    cr_assert_eq(add_cmd_to_path(path_array, NULL), 84);
}

Test(add_cmd_to_path, NULL_all){
    cr_assert_eq(add_cmd_to_path(NULL, NULL), 84);
}

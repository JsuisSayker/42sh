/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** move_in_folder_sub
*/

#include <unistd.h>

#include "macro.h"
#include "proto.h"
#include "struct.h"
#include "proto_lib.h"

int return_old_foldre_sub(base_minishell_t *base, char *last_pwd, char *my_pwd)
{
    int len_pwd = 0;
    if (last_pwd == NULL || my_pwd == NULL || base == NULL)
        return KO;
    if ((len_pwd = my_strlen(my_pwd)) == KO)
        return KO;
    if (my_strncmp(last_pwd, my_pwd, len_pwd) == OK){
        write(2, ": No such file or directory.\n", 29);
        return KO;
    }
    if (move_in_folder(base, last_pwd) != OK){
        free(my_pwd);
        free(last_pwd);
        return KO;
    }
    return OK;
}

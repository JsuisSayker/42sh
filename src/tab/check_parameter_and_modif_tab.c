/*
** EPITECH PROJECT, 2023
** Minishell2
** File description:
** check_parameter
*/

#include <unistd.h>

#include "proto.h"
#include "macro.h"
#include "struct.h"
#include "proto_lib.h"

static int check_parameter_sub(all_str_t *all_str, int *x)
{
    if (all_str->str[*x] == '|'){
        if (check_pipe(all_str, x) != OK)
            return KO;
    }
    if (all_str->str[*x] == '<' || all_str->str[*x] == '>'){
        if (check_redirector_input(all_str, x) != OK)
            return KO;
    }
    return OK;
}

static int check_parameter(all_str_t *all_str)
{
    if (all_str == NULL)
        return 1;
    for (int x = 0; all_str->str[x] != '\0' && x < all_str->len_str; x += 1){
        if (check_parameter_sub(all_str, &x) != OK)
            return KO;
    }
    return OK;
}

int check_parameter_and_modif_tab(base_minishell_t *base)
{
    all_str_t *all_str = malloc(sizeof(all_str_t));
    if (all_str == NULL || base == NULL)
        return KO;
    for (int y = 0; base->command[y] != NULL; y += 1){
        if ((all_str->str = my_strcpy(base->command[y])) == NULL)
            return KO;
        all_str->len_str = my_strlen(all_str->str);
        if ((base->return_value = check_parameter(all_str)) != OK){
            free(all_str->str);
            return KO;
        }
        free(all_str->str);
    }
    free(all_str);
    return OK;
}

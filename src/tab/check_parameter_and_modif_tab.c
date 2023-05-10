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
#include "struct_args_for_entry.h"

static int check_parameter_sub(all_str_t *all_str, args_s_t *args, int *x)
{
    if (all_str->str[*x] == '|'){
        if (check_pipe(all_str, args, x) != OK)
            return KO;
        return OK;
    }
    if (all_str->str[*x] == '<'){
        if (check_redirector_left(all_str, args, x) != OK)
            return KO;
        return OK;
    }
    if (all_str->str[*x] == '>'){
        if (check_redirector_right(all_str, args, x) != OK)
            return KO;
        return OK;
    }
    return OK;
}

static int check_parameter(base_minishell_t *base, all_str_t *all_str,
args_s_t *args)
{
    if (!all_str || !args)
        return KO;
    args->invalide = 0;
    args->ambigous_output = 0;
    args->ambigous_input = 0;
    args->missing = 0;
    for (int x = 0; all_str->str[x] != '\0' && x < all_str->len_str; x += 1){
        if (check_parameter_sub(all_str, args, &x) != OK)
            return KO;
        if (x > all_str->len_str - 1)
            break;
    }
    if (error_message_parameter(base, args) == KO)
        return KO;
    return OK;
}

int check_parameter_and_modif_tab(base_minishell_t *base)
{
    all_str_t *all_str = malloc(sizeof(all_str_t));
    args_s_t *args = malloc(sizeof(args_s_t));
    if (!all_str || !base || !args)
        return KO;
    for (int y = 0; base->command[y] != NULL; y += 1){
        if ((all_str->str = my_strcpy(base->command[y])) == NULL)
            return KO;
        all_str->len_str = my_strlen(all_str->str);
        if ((base->return_value = check_parameter(base, all_str, args)) != OK){
            free(args);
            free(all_str->str);
            free(all_str);
            return KO;
        }
        free(all_str->str);
    }
    free(all_str);
    return OK;
}

/*
** EPITECH PROJECT, 2023
** Minishell2
** File description:
** check_parameter
*/

#include <unistd.h>

#include "macro.h"
#include "proto.h"
#include "proto_lib.h"
#include "struct.h"
#include "struct_args_for_entry.h"

static int count_redirector(all_str_t *all_str, int *x)
{
    int nbr_redirector = 0;
    for (int i = *x; all_str->str[i] != '\0'; i += 1){
        if (all_str->str[i] == '<')
            nbr_redirector += 1;
        else
            return nbr_redirector;
    }
    return nbr_redirector;
}

static int check_after(all_str_t *all_str, args_s_t *args_s, int *x)
{
    int args = 0;
    if (!all_str || !args_s || !x)
        return KO;
    for (int i = (*x + args_s->nbr_parameter); all_str->str[i] != '\0'; i += 1){
        if (all_str->str[i] != '|' && all_str->str[i] != '<' &&
        all_str->str[i] != '>' && all_str->str[i] != ' ' &&
        all_str->str[i] != '&'){
            args = 1;
            break;
        }
        if (all_str->str[i] == '|' || all_str->str[i] == '<' ||
        all_str->str[i] == '>' || all_str->str[i] == '&')
            break;
    }
    if (args == 0)
        args_s->missing = 1;
    if ((all_str->len_str) == (*x + args_s->nbr_parameter))
        args_s->missing = 1;
    return OK;
}

static int condition_mulitple(all_str_t *all_str, args_s_t *args, int *x,
int i)
{
    int move = 0;
    if (!all_str || !args || !x)
        return KO;
    move = i;
    if (all_str-> str[i] == '<'){
        args->ambigous_input = 1;
        if (check_redirector_left(all_str, args, &move) == KO)
            return KO;
    }
    if (all_str-> str[i] == '>'){
        if (check_redirector_right(all_str, args, &move) == KO)
            return KO;
    }
    if (all_str->str[i] == '|')
        if (check_pipe(all_str, args, &move) == KO)
            return KO;
    *x = move;
    return OK;
}

static int check_multiple(all_str_t *all_str, args_s_t *args, int *x)
{
    int i = 0;
    if (!all_str || !args || !x)
        return KO;
    for (i = *x + args->nbr_parameter; all_str->str[i] != '\0'; i += 1){
        if (condition_mulitple(all_str, args, x, i) != OK)
            return KO;
    }
    return OK;
}

int check_redirector_left(all_str_t *all_str, args_s_t *args_s, int *x)
{
    if (all_str->len_str <= *x){
        args_s->missing = 1;
        return OK;
    }
    if ((args_s->nbr_parameter = count_redirector(all_str, x)) == KO)
        return KO;
    if (args_s->nbr_parameter > 2){
        if (write(2, "Missing name for redirect.\n", 27) == -1)
            return KO;
        return KO;
    }
    if (check_before(all_str, args_s, x) != OK)
        return KO;
    if (check_after(all_str, args_s, x) != OK)
        return KO;
    if (check_multiple(all_str, args_s, x) != OK)
        return KO;
    *x += args_s->nbr_parameter;
    return OK;
}

/*
** EPITECH PROJECT, 2023
** Minishell2
** File description:
** check_pipe
*/

#include <unistd.h>

#include "macro.h"
#include "proto.h"
#include "proto_lib.h"
#include "struct.h"

static int check_after(all_str_t *all_str, args_s_t * args_s, int *x,
int nbr_pipe)
{
    int args = 0;
    if (!args_s || !all_str || !x)
        return KO;
    for (int i = (*x + nbr_pipe); all_str->str[i] != '\0'; i += 1){
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
        args_s->invalide = 1;
    return OK;
}

int check_before(all_str_t *all_str, args_s_t * args_s, int *x)
{
    int args = 0;
    if (!args_s || !all_str || !x)
        return KO;
    for (int i = *x - 1; i >= 0; i -= 1){
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
        args_s->invalide = 1;
    return OK;
}

static int count_pipe(all_str_t *all_str, int *x)
{
    int nbr_pipe = 0;
    if (!all_str || !x)
        return KO;
    for (int i = *x; all_str->str[i] != '\0'; i += 1) {
        if (all_str->str[i] == '|')
            nbr_pipe += 1;
        else
            return nbr_pipe;
    }
    return nbr_pipe;
}

int check_pipe(all_str_t *all_str, args_s_t *args, int *x)
{
    int nbr_pipe = 0;
    if (!args || !all_str || !x)
        return KO;
    if ((nbr_pipe = count_pipe(all_str, x)) == KO)
        return KO;
    if (nbr_pipe > 2) {
        if (write(2, "Invalid null command.\n", 22) == -1)
            return 1;
        return 1;
    }
    if (check_before(all_str, args, x) != OK)
        return KO;
    if (check_after(all_str, args, x, nbr_pipe) != OK)
        return KO;
    *x += nbr_pipe;
    return OK;
}

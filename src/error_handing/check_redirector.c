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
        if (all_str->str[i] == '>' || all_str->str[i] == '<')
            nbr_redirector += 1;
        else
            return nbr_redirector;
    }
    return nbr_redirector;
}

static int check_multiple(args_s_t *args, char *str, int *x, int nbr_redirect)
{
    for (int i = *x + nbr_redirect; str[i] != '\0'; i += 1){
        if (str[i] == '<' || str[i] == '>' || str[i] == '|'){
            args->multiple = 1;
            break;
        }
    }
    if (error_message_redirector(args) != OK){
        return 1;
    }
    return OK;
}

static int check_before_after(args_s_t *args, char *str, int *x,
int nbr_redirect)
{
    for (int i = *x; i > 0; i -= 1){
        if (str[i] != '|' && str[i] != '<' && str[i] != '>' && str[i] != ' '){
            args->before = 1;
            break;
        } else if (str[i] == '|' && str[i] == '<' && str[i] == '>')
            break;
    }
    if (0 == *x)
        args->before = 1;
    if (check_multiple(args, str, x, nbr_redirect) != OK)
        return 1;
    return OK;
}

static int check_before_and_after(args_s_t *args, all_str_t *all_str, int *x,
int nbr_redirect)
{
    for (int i = (*x + nbr_redirect); all_str->str[i] != '\0'; i += 1){
        if (all_str->str[i] != '|' && all_str->str[i] != '<' &&
        all_str->str[i] != '>' && all_str->str[i] != ' '){
            args->after = 1;
            break;
        } else if (all_str->str[i] == '|' && all_str->str[i] == '<' &&
        all_str->str[i] == '>')
            break;
    }
    if ((all_str->len_str) == (*x + nbr_redirect))
        args->after = 1;
    if (check_before_after(args, all_str->str, x, nbr_redirect) != OK)
        return KO;
    return OK;
}

int check_redirector_input(all_str_t *all_str, int *x)
{
    args_s_t *args = malloc(sizeof(args_s_t));
    args->after = 0;
    args->before = 0;
    args->multiple = 0;
    int nbr_redirector = count_redirector(all_str, x);
    if (nbr_redirector > 2){
        if (write(2, "Missing name for redirect.\n", 27) == -1)
            return 1;
        free(args);
        return 1;
    }
    if (check_before_and_after(args, all_str, x, nbr_redirector) != OK){
        free(args);
        return 1;
    }
    *x += nbr_redirector;
    free(args);
    return OK;
}

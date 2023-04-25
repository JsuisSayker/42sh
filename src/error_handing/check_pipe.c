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

static int check_before_after(char *str, int *x, int *args)
{
    for (int i = *x - 1; i >= 0; i -= 1){
        if (str[i] != '|' && str[i] != '<' && str[i] != '>' && str[i] != ' '){
            *args += 1;
            break;
        }
        if (str[i] == '|' && str[i] == '<' && str[i] == '>')
            break;
    }
    if (*args != 2){
        if (write(2, "Invalid null command.\n", 22) == -1)
            return 1;
        return 1;
    }
    return OK;
}

static int check_before_and_after(char *str, int *x, int nbr_pipe)
{
    int args = 0;
    for (int i = (*x + nbr_pipe); str[i] != '\0'; i += 1){
        if (str[i] != '|' && str[i] != '<' && str[i] != '>' && str[i] != ' '){
            args += 1;
            break;
        }
        if (str[i] == '|' && str[i] == '<' && str[i] == '>')
            break;
    }
    if (check_before_after(str, x, &args) != OK)
        return KO;
    return OK;
}

static int count_pipe(all_str_t *all_str, int *x)
{
    int nbr_pipe = 0;
    for (int i = *x; all_str->str[i] != '\0'; i += 1){
        if (all_str->str[i] == '|')
            nbr_pipe += 1;
        else
            return nbr_pipe;
    }
    return nbr_pipe;
}

int check_pipe(all_str_t *all_str, int *x)
{
    int nbr_pipe = count_pipe(all_str, x);
    if (nbr_pipe > 2){
        if (write(2, "Invalid null command.\n", 22) == -1)
            return 1;
        return 1;
    }
    if (check_before_and_after(all_str->str, x, nbr_pipe) != OK)
        return 1;
    *x += nbr_pipe;
    return OK;
}

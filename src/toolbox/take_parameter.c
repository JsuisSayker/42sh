/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** take_parameter
*/

#include <unistd.h>

#include "macro.h"
#include "proto.h"
#include "proto_lib.h"

static int check_single_parameter(char *str, int *nbr_parameter)
{
    if (!str)
        return KO;
    if (str[0] > '<' || str[0] > '>' || str[0] > '|' || str[0] > '&' ||
    str[0] > ';'){
        *nbr_parameter = 1;
    }
    return OK;
}

static int condition(char *str, int *x, int *nbr_parameter)
{
    if (!str)
        return KO;
    if (*x == 0){
        if ((str[*x] == '|' && str[*x + 1] != '|') ||
        (str[*x] == '|' && str[*x + 1] == '|') ||
        (str[*x] == '&' && str[*x + 1] == '&') ||
        (str[*x] == '>' && str[*x + 1] != '>') ||
        (str[*x] == '<' && str[*x + 1] != '<'))
            *nbr_parameter += 1;
        return OK;
    }
    if ((str[*x] == '|' && str[*x + 1] != '|' && str[*x - 1] != '|') ||
        (str[*x] == '|' && str[*x + 1] == '|' && str[*x - 1] != '|') ||
        (str[*x] == '&' && str[*x + 1] == '&' && str[*x - 1] != '&') ||
        (str[*x] == '>' && str[*x + 1] != '>' && str[*x - 1] != '>') ||
        (str[*x] == '<' && str[*x + 1] != '<' && str[*x - 1] != '<') ||
        str[*x] == ';')
            *nbr_parameter += 1;
    return OK;
}

static int take_parameter_sub(char *str, int *nbr_parameter)
{
    int x = 0;
    if (!str)
        return KO;
    while (str[x] != '\0') {
        if (condition(str, &x, nbr_parameter) == KO)
            return KO;
        if ((str[x] == '>' && str[x + 1] == '>') ||
        (str[x] == '<' && str[x + 1] == '<')){
            *nbr_parameter += 1;
            x += 1;
        }
        x += 1;
    }
    return OK;
}

int take_parameter(char *str)
{
    int len = 0;
    int nbr_parameter = 0;
    if (str == NULL)
        return KO;
    if ((len = my_strlen(str)) == KO)
        return KO;
    if (len == 1){
        if (check_single_parameter(str, &nbr_parameter) == KO)
            return OK;
        return nbr_parameter;
    }
    if (take_parameter_sub(str, &nbr_parameter) == KO)
        return KO;
    return nbr_parameter;
}

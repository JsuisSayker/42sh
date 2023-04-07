/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** ambiguous_output_redirect
*/

#include "mysh.h"

static int find_second_separator_sub(mysh_t *mysh_need, char **redirector,
int j)
{
    for (int y = 0;  redirector[y] != NULL; y += 1){
        if (my_str_cmp(mysh_need->command_split[j][0], redirector[y]) == OK) {
            free_command_split(mysh_need->command_split);
            write(2, "Ambiguous output redirect.\n", 27);
            mysh_need->return_value = 1;
            return KO;
        }
    }
    return OK;
}

static int find_second_separator(mysh_t *mysh_need, char **redirector, int *i)
{
    for (int j = (*i) + 1; mysh_need->command_split[j] != NULL; j += 1){
        if (my_str_cmp(mysh_need->command_split[j][0], "|") == OK ||
        my_str_cmp(mysh_need->command_split[j][0], ";") == OK){
            (*i) = j + 1;
            return OK;
        }
        if (find_second_separator_sub(mysh_need, redirector, j) == KO)
            return KO;
    }
    return OK;
}

static int find_first_separator_sub(mysh_t *mysh_need,
char **redirector, int *i, int k)
{
    if (my_str_cmp(mysh_need->command_split[(*i)][0], redirector[k]) == OK) {
        if (find_second_separator(mysh_need, redirector, i) == KO)
            return KO;
    }
    return OK;
}

static int find_first_separator(mysh_t *mysh_need, char **redirector, int *i)
{
    for (int k = 0; redirector[k] != NULL; k += 1){
        if (find_first_separator_sub(mysh_need, redirector, i,
        k) == KO)
            return KO;
    }
    return OK;
}

int ambiguous_output_redirect(mysh_t *mysh_need)
{
    char *redirector[] = {">>", ">", "<<", "<", NULL };
    if (basic_ambiguous_output_redirect(mysh_need, redirector) == KO)
        return KO;
    int i = 0;
    for (; mysh_need->command_split[i] != NULL; i += 1){
        if (find_first_separator(mysh_need, redirector, &i) == KO)
            return KO;
    }
    return OK;
}

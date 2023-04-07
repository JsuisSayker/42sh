/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** basic_ambiguous_output_redirect
*/

#include "mysh.h"

int basic_ambiguous_output_redirect(mysh_t *mysh_need, char **redirector)
{
    int len_str_split = 0;
    for (; mysh_need->command_split[len_str_split] != NULL;
    len_str_split += 1);
    for (int i = 0; redirector[i] != NULL; i += 1){
        if (my_str_cmp(mysh_need->command_split[len_str_split - 1][0],
        redirector[i]) == OK) {
            free_command_split(mysh_need->command_split);
            write(2, "Ambiguous output redirect.\n", 27);
            mysh_need->return_value = 1;
            return KO;
        }
    }
    return OK;
}

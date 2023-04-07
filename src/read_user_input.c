/*
** EPITECH PROJECT, 2023
** read the user input in the game
** File description:
** read_user_input
*/

#include "mysh.h"

int split_splited_str(mysh_t *mysh_need, char **redirector)
{
    int len_str_split = my_map_len(mysh_need->str_split);
    mysh_need->command_split = malloc(sizeof(char **) * (len_str_split + 1));
    if (mysh_need->command_split == NULL)
        return KO;
    for (int i = 0; mysh_need->str_split[i] != NULL; i += 1){
        mysh_need->command_split[i] = spliter(mysh_need->str_split[i], " \t");
    }
    mysh_need->command_split[len_str_split] = NULL;
    free_spliter(mysh_need->str_split, redirector);
    return OK;
}

int read_user_input(mysh_t *mysh_need)
{
    size_t len = 0;
    char *redirector[] = { ";", "|", ">>", ">", "<<", "<", NULL };
    if (getline(&(mysh_need->buffer), &len, stdin) == -1) {
        free_all(mysh_need);
        return KO;
    }
    if ((mysh_need->buffer)[my_str_len(mysh_need->buffer) - 1] == '\n')
        (mysh_need->buffer)[my_str_len(mysh_need->buffer) - 1] = '\0';
    mysh_need->str_split = spliter_redirector(mysh_need->buffer, redirector);
    free(mysh_need->buffer);
    if (mysh_need->str_split != NULL){
        if (split_splited_str(mysh_need, redirector) == KO)
            return KO;
    }
    return OK;
}

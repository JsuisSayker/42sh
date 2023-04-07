/*
** EPITECH PROJECT, 2023
** new_project_folder_file
** File description:
** mysh
*/

#include "mysh.h"

int loop_all_command(mysh_t *mysh_need)
{
    fd_need_t fd_need_n;
    initialise_fd_need_structure(mysh_need->command_split, &fd_need_n);
    for (mysh_need->nb_field = 0; mysh_need->command_split\
        [mysh_need->nb_field] != NULL; mysh_need->nb_field += 1) {
        if (is_str_redirector(mysh_need->command_split[mysh_need->nb_field]\
            [0]) == OK)
            launch_command(mysh_need, &fd_need_n);
    }
    for (int i = 0; i < fd_need_n.nb_redirector; i += 1) {
        free(fd_need_n.pipe_fd[i]);
    }
    free(fd_need_n.pipe_fd);
    free(fd_need_n.all_pid);
    free_command_split(mysh_need->command_split);
    return OK;
}

int missing_name_for_redirect(mysh_t *mysh_need)
{
    char *redirector[] = {">>", ">", "<<", "<", NULL };
    for (int i = 0; redirector[i] != NULL; i += 1){
        if (my_str_cmp(mysh_need->command_split[0][0],
        redirector[i]) == OK) {
            free_command_split(mysh_need->command_split);
            write(2, "Missing name for redirect.\n", 27);
            mysh_need->return_value = 1;
            return KO;
        }
    }
    return OK;
}

int invalid_null_command_begin_end(mysh_t *mysh_need)
{
    int len_str_split = 0;
    for (; mysh_need->command_split[len_str_split] != NULL; len_str_split += 1);
    char *redirector[] = {"|", ">>", ">", "<<", "<", NULL };
    for (int i = 0; redirector[i] != NULL; i += 1){
        if (my_str_cmp(mysh_need->command_split[0][0], redirector[i]) == OK ||
        my_str_cmp(mysh_need->command_split[len_str_split - 1][0],
        redirector[i]) == OK) {
            free_command_split(mysh_need->command_split);
            write(2, "Invalid null command.\n", 22);
            mysh_need->return_value = 1;
            return KO;
        }
    }
    return OK;
}

int error_message_handling(mysh_t *mysh_need)
{
    if (mysh_need->str_split != NULL) {
        if (missing_name_for_redirect(mysh_need) == KO)
            return KO;
        if (ambiguous_output_redirect(mysh_need) == KO)
            return KO;
        if (invalid_null_command_begin_end(mysh_need) == KO)
            return KO;
    }
    return OK;
}

int mysh(char **env)
{
    mysh_t mysh_need;
    intialize_struct_mysh_value(&mysh_need, env);
    while (true) {
        prompt();
        if (read_user_input(&mysh_need) == KO)
            return mysh_need.return_value;
        if (mysh_need.str_split != NULL && error_message_handling(&mysh_need) ==
            OK)
            loop_all_command(&mysh_need);
    }
}

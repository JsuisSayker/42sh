/*
** EPITECH PROJECT, 2023
** secondary process
** File description:
** secondary_process
*/

#include "minishell.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int secondary_process(char **env, char *buf_size)
{
    char **command_with_args = my_str_to_word_array(buf_size, ".-/0123456789");
    execve(command_with_args[0], command_with_args, env);
    char *path = path_finder(env, "PATH=");
    char **possible_path = my_str_to_word_array(path, "./-_");
    test_all_path_with_cmd(command_with_args, possible_path, buf_size, env);
    write(2, command_with_args[0], my_strlen(command_with_args[0]));
    int fd = open(command_with_args[0], O_RDONLY);
    if (fd == -1)
        write(2, ": Command not found.\n", 21);
    else {
        write(2, ": Permission denied.\n", 21);
        close(fd);
    }
    free_commands(command_with_args, possible_path, buf_size, env);
    exit(1);
}

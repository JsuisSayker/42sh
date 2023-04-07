/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "minishell.h"

int main(int argc, char *const *const argv, char **env)
{
    if (argc != 1 || argv[1] != NULL)
        return KO;
    char **new_env = env_cpy(env);
    return launch_shell(new_env);
}

/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include "proto.h"

int main(int argc, char const *const *argv, char **env)
{
    if (check_argc_argv(argc, argv) != 0)
        return 84;
    return minishell_one(env);
}

/*
** EPITECH PROJECT, 2023
** my_scripts
** File description:
** main
*/

#include "mysh.h"

int main(int argc, char **argv, char **env)
{
    if (argc != 1 || argv[1] != NULL || env == NULL)
        return KO;
    char **my_env = copy_env(env);
    if (my_env == NULL)
        return KO;
    return mysh(my_env);
}

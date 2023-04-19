/*
** EPITECH PROJECT, 2023
** Minishell1
** File description:
** move_in_folder
*/

#include <unistd.h>

#include "proto.h"
#include "macro.h"
#include "struct.h"
#include "proto_lib.h"

static char *get_my_pwd(void)
{
    char *buffer = malloc(sizeof(char) * 4096);
    if (getcwd(buffer, 4095) == NULL)
        return NULL;
    return buffer;
}

int move_in_folder(base_minishell_t *base, char *direction)
{
    int len_direction = my_strlen(direction);
    char *old_pwd = get_my_pwd();
    if (old_pwd == NULL)
        return KO;
    if (chdir(direction) == -1){
        write(2, direction, len_direction);
        write(2, ": no such file or directory\n", 28);
        free(old_pwd);
        return KO;
    } else {
        char *pwd = get_my_pwd();
        if (setenv_reprogramming(base, "PWD", pwd) != OK)
            return KO;
        if (setenv_reprogramming(base, "OLDPWD", old_pwd) != OK)
            return KO;
        free(pwd);
    }
    free(old_pwd);
    return OK;
}

int return_old_folder(base_minishell_t *base)
{
    char *my_pwd = NULL;
    char *last_pwd = NULL;
    if (base == NULL)
        return KO;
    if ((last_pwd = take_in_env(base->env, "OLDPWD=")) == NULL)
        write(2, ": No such file or directory.\n", 29);
    my_pwd = get_my_pwd();
    if (last_pwd == NULL || my_pwd == NULL)
        return KO;
    int len_pwd = my_strlen(my_pwd);
    if (my_strncmp(last_pwd, my_pwd, len_pwd) == OK)
        write(2, ": No such file or directory.\n", 29);
    if (move_in_folder(base, last_pwd) != OK){
        free(my_pwd);
        free(last_pwd);
        return KO;
    }
    free(my_pwd);
    return OK;
}

int move_to_home(base_minishell_t *base)
{
    char *home = take_in_env(base->env, "HOME=");
    if (home == NULL)
        return KO;
    if (move_in_folder(base, home) != OK){
        return KO;
    }
    return OK;
}

int move_from_home(base_minishell_t *base, char **tab)
{
    if (tab[1][1] == '\0'){
        if (move_to_home(base) != OK)
            return KO;
    } else {
        char *home = take_in_env(base->env, "HOME=");
        char *move_home = my_strcat(home, tab[1]);
        if (move_in_folder(base, move_home) != OK){
            free(move_home);
            return KO;
        }
        free(move_home);
    }
    return OK;
}

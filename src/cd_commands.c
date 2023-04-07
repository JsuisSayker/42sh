/*
** EPITECH PROJECT, 2023
** cd_commands
** File description:
** cd commands
*/

#include "minishell.h"
#include <stdlib.h>
#include <unistd.h>

static void create_usable_variables(char **directory, char *path_to_go,
char **env)
{
    for (int i = 1; i < my_strlen(directory[1]); i += 1) {
        path_to_go[i - 1] = directory[1][i];
    }
    char *true_home_path = malloc(sizeof(char) * (my_strlen(path_finder(env,
    "HOME=")) + 1));
    true_home_path[my_strlen(path_finder(env, "HOME="))] = '\0';
    for (int i = 0; i < my_strlen(path_finder(env, "HOME=")); i += 1) {
        true_home_path[i] = path_finder(env, "HOME=")[i];
    }
    char *special_case = malloc(sizeof(char) * ((my_strlen(directory[1]) + 1)
    + my_strlen(path_finder(env, "HOME="))));
    special_case[(my_strlen(directory[1])) +
    my_strlen(path_finder(env, "HOME="))] = '\0';
    for (int i = 0; i <= my_strlen(true_home_path); i += 1) {
        special_case[i] = true_home_path[i];
    }
    my_strcat(special_case, path_to_go);
    chdir(special_case);
}

static void replace_pwd(char *pwd, char **env)
{
    char *new_pwd = malloc(sizeof(char) * (my_strlen(pwd) + 1));
    new_pwd[my_strlen(pwd)] = '\0';
    getcwd(new_pwd, my_strlen(pwd));
    pwd = malloc (sizeof(char) * (my_strlen(new_pwd) + 1));
    pwd[my_strlen(new_pwd)] = '\0';
    for (int i = 0; i <= my_strlen(new_pwd); i += 1) {
        pwd[i] = new_pwd[i];
    }
    change_the_value_in_env(&env, (my_strlen("PWD=") + my_strlen(pwd)),
    setup_new_complete_str((my_strlen("PWD=") + my_strlen(pwd)), "PWD=", pwd),
    "PWD=");
}

int cd_commands(char **env, char *buf_size)
{
    char **directory = my_str_to_word_array(buf_size, "~/-.0123456789");
    char *path_to_go = malloc(sizeof(char) * (my_strlen(directory[1]) + 1));
    char *pwd = path_finder(env, "PWD=");
    if (directory[1][0] == '~') {
        path_to_go[(my_strlen(directory[1]) - 1)] = '\0';
        create_usable_variables(directory, path_to_go, env);
        change_the_value_in_env(&env, (my_strlen("OLDPWD=") + my_strlen(pwd)),
        setup_new_complete_str((my_strlen("OLDPWD=") + my_strlen(pwd)),
        "OLDPWD=", pwd), "OLDPWD=");
        replace_pwd(pwd, env);
    } else {
        chdir(directory[1]);
    }
    return OK;
}

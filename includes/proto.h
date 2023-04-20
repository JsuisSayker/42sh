/*
** EPITECH PROJECT, 2023
** proto.h
** File description:
** proto
*/

#include <stdlib.h>
#include "struct.h"
#include "struct_args_for_entry.h"

#ifndef PROTO_H_
    #define PROTO_H_

    int minishell_one(int ac, char const *const *av, char **env);

        /* toolbox */
    int free_all(base_minishell_t *base, need_tab_t *need_tab);
    int free_tab_int(need_tab_t *need_tab);
    int free_str(all_str_t *all_str);
    int free_big_tab(char ***tab);
    int free_tab_char(char **tab);
    int check_if_redirector(char *str, need_tab_t *need_tab);
    int count_parameter_sub(char **tab);
    int count_parameter(char *str);
    int take_parameter(char *str);
    int starting(void);
    int take_entry(base_minishell_t *base, char **env, int *restart,
    int *nbr_parameter);
    char *take_in_env(char **env, char *str);
    char **take_path(char **env, char *str);
    char **take_env(char **env);

        /* tab */
    char **reduce_tab(char **src, char *str);
    char **remove_of_tab(char **src, char *str);
    char **enlarge_tab(char **src, char *variable, char *value);
    char **add_array_to_tab(all_str_t *all_str, char **src, char *value,
    int len_src);
    char **modif_array_to_tab(all_str_t *all_str, char **src, char *value,
    int len_src);
    int check_parameter_and_modif_tab(base_minishell_t *base);
    int entry_w_parameter_or_not(base_minishell_t *base, char *entry,
    int *nbr_parameter);

        /* error_handing */
    void error_and_free_message_cmd(base_minishell_t *base, char **tab);
    int check_redirector_input(all_str_t *all_str, int *x);
    int check_argc_argv(int ac, char const *const *av);
    int error_message_redirector(args_s_t *args);
    int check_pipe(all_str_t *all_str, int *x);

        /* command */
    void close_fonction(base_minishell_t *base, need_tab_t *need_tab);
    int child_display_parameter(base_minishell_t *base, need_tab_t *need_tab);
    int command_with_parameter(base_minishell_t *base, need_tab_t *need_tab);
    int duplicate_fonction(base_minishell_t *base, need_tab_t *need_tab);
    int check_fontion_build(base_minishell_t *base, need_tab_t *need_tab,
    char **tab_command);
    int fonction_build(base_minishell_t *base, need_tab_t *need_tab,
    char **tab_command);
    int execution_fonction_build(base_minishell_t *base, char **tab, int n);
    int parameter_after_command(base_minishell_t *base, need_tab_t *need_tab);
    int check_command_and_execute(base_minishell_t *base, need_tab_t *need_tab);
    int command(base_minishell_t *base, need_tab_t *need_tab, char **tab);
    int unsetenv_exit(base_minishell_t *base, char **tab);
    int setenv_exit(base_minishell_t *base, char **tab);
    int print_env(char **env);
    int setenv_reprogramming(base_minishell_t *base, char *variable,
    char *value);
    int child_display(base_minishell_t *base, need_tab_t *need_tab,
    pid_t pid, int value);
    int unsetenv_reprogramming(base_minishell_t *base, char *str);
    char *string_command(char *path, char *entry);

        /* cd */
    int move_in_folder(base_minishell_t *base, char *direction);
    int cd_reprogramming(base_minishell_t *base, char **tab);
    int move_from_home(base_minishell_t *base, char **tab);
    int return_old_folder(base_minishell_t *base);
    int move_to_home(base_minishell_t *base);

#endif /* !PROTO_H_ */

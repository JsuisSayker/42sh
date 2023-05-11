/*
** EPITECH PROJECT, 2023
** proto.h
** File description:
** proto
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "struct.h"
#include "struct_args_for_entry.h"

#ifndef PROTO_H_
    #define PROTO_H_

    int minishell_one(char **env);
    char *pwd_function(void);
    int alias(base_minishell_t *base, char **tab);
    int history(base_minishell_t *base, char **tab);

        /* toolbox */
    int free_all(base_minishell_t *base, need_tab_t *need_tab);
    int free_tab_int(need_tab_t *need_tab);
    char *my_load_fd_in_memory(int fd);
    int free_str(all_str_t *all_str);
    int free_big_tab(char ***tab);
    int free_tab_char(char **tab);
    int check_if_redirector(char *str, need_tab_t *need_tab);
    int count_parameter_sub(char **tab);
    int count_parameter(char *str);
    int take_parameter(char *str);
    int starting(void);
    int take_entry(base_minishell_t *base, int *restart,
    int *nbr_parameter);
    char *take_in_env(char **env, char *str);
    char **take_path(char **env, char *str);
    char **take_env(char **env);
    int find_alias_of_the_command(char **str_split_line, char **str_plit);
    int replace_alias_with_command(base_minishell_t *base, char **entry);
    int replace_alias_with_parameter(base_minishell_t *base);
    int append_stdout_to_file(const char *filename, char *str);
    int put_stdout_in_file(const char *filename, char *str);
    char *clean_str(char *str);
    char *tab_to_char(char **tab);

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
    char *my_load_file_in_memory(const char *filename);
    int append_cmd_to_history(const char *filename, char *str);
    int append_str_to_file(const char *filename, char *str);
    int display_file(const char *filename);

        /* error_handing */
    void error_and_free_message_cmd(base_minishell_t *base, char **tab);
    int check_redirector_left(all_str_t *all_str, args_s_t *args_s, int *x);
    int check_redirector_right(all_str_t *all_str, args_s_t *args_s, int *x);
    int check_argc_argv(int ac, char const *const *av);
    int error_message_parameter(base_minishell_t * base, args_s_t *args);
    int check_before(all_str_t *all_str, args_s_t * args_s, int *x);
    int check_pipe(all_str_t *all_str, args_s_t *args, int *x);
    int check_for_backticks(base_minishell_t *base);

        /* command */
    void close_function(base_minishell_t *base, need_tab_t *need_tab);
    int check_left_redirector_and_param(base_minishell_t *base,
    need_tab_t *need_tab);
    int echo_command(base_minishell_t *base, char **command);
    int child_display_parameter(base_minishell_t *base, need_tab_t *need_tab);
    int command_with_parameter(base_minishell_t *base, need_tab_t *need_tab);
    int duplicate_function(base_minishell_t *base, need_tab_t *need_tab);
    int check_function_build(base_minishell_t *base, need_tab_t *need_tab,
    char **tab_command);
    int function_build(base_minishell_t *base, char **tab_command);
    int check_command_and_execute(base_minishell_t *base, need_tab_t *need_tab);
    int command(base_minishell_t *base, need_tab_t *need_tab, char **tab);
    int unsetenv_exit(base_minishell_t *base, char **tab);
    int setenv_exit(base_minishell_t *base, char **tab);
    int print_env(char **env);
    int setenv_reprogramming(base_minishell_t *base, char *variable,
    char *value);
    int child_display(base_minishell_t *base, need_tab_t *need_tab,\
    pid_t pid, int value);
    int unsetenv_reprogramming(base_minishell_t *base, char *str);
    char *string_command(char *path, char *entry);
    int echo_command(base_minishell_t *base, char **command);
    int file_function(base_minishell_t *base, need_tab_t *need_tab, int *x);
    int print_table(int len_tab, FILE *fd, char **tab);
    int special_case(char **str_split_text, char **tab, FILE *fd);
    int place_between_existing_alias(char **str_split_text, int i, char **tab,\
    FILE *fd);
    int already_exist(char *key_variable, char **tab, FILE *fd, int *is_print);
    int right_redirector(base_minishell_t *base, need_tab_t *need_tab,
    char **command);
    int left_redirector(base_minishell_t *base, need_tab_t *need_tab,
    char **tab_command);
    void execution(base_minishell_t *base, need_tab_t *need_tab, char **tab);
    int display_error_command(char *cmd);
    int execute_cmd_and_cmd(base_minishell_t *base, need_tab_t *need_tab);
    void check_cmd_with_slash(bool *search_in_path_cmd, char **tab);
    void print_error_and_free(char **tab, base_minishell_t *base,
    need_tab_t *need_tab);
    int special_exec(base_minishell_t *base, need_tab_t *need_tab, int *x,
    int *client);


        /* cd */
    int move_in_folder(base_minishell_t *base, char *direction);
    int cd_reprogramming(base_minishell_t *base, char **tab);
    int move_from_home(base_minishell_t *base, char **tab);
    int return_old_folder(base_minishell_t *base);
    int move_to_home(base_minishell_t *base);
    int return_old_foldre_sub(base_minishell_t *base, char *last_pwd,
    char *my_pwd);

#endif /* !PROTO_H_ */

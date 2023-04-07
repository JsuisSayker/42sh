/*
** EPITECH PROJECT, 2023
** my_str lib functions header
** File description:
** my_str
*/

#include <sys/wait.h>
#include "pipe_elem.h"

#ifndef STR_LIB
    #define STR_LIB
    #define OK 0;
    #define KO 84;
    int launch_shell(char **env);
    int exec_command_and_binaries(char *new_splited_str, char **env,
    int *returned_value);
    char *path_finder(char **env, char *str);
    int my_putstr (char const *str);
    int is_sbustr_in_str(char const *s1, char const *s2);
    int my_compute_power_rec (int nb, int p);
    int my_isneg (int n);
    int my_strcat(char *dest, char const *src);
    int my_strcmp(char const *s1, char const *s2);
    int my_strncmp(char const *s1, char const *s2, int n);
    char *my_strcpy (char *dest, char const *src);
    int my_strlen (char const *str);
    char *my_strlowcase(char *str);
    char *my_strncpy(char *dest, char const *src, int n);
    char *my_strstr(char *str, char const *to_find);
    char *my_strupcase(char *str);
    int my_swap (int *a, int *b);
    int my_char_isalpha(const char c);
    int my_str_is_alphanum(const char *str);
    int count_words_in_str(char *str);
    int len_of_an_str(char *str, int count, char *separator);
    char **my_str_to_word_array(char *str, char *separator);
    char **env_cpy(char **env);
    int built_in(char ***env, char *buf_size, int *built_in_value,
    int *returned_value);
    int env_built_in(char **env);
    int count_line_in_env(char **env);
    int setenv_built_in(char ***env, char *buf_size);
    char *setup_command_with_eq(char **command);
    char *setup_new_complete_str(int len_new_str, char *command_with_eq_in_env,
    char *new_value_in_env);
    int good_exit_case(char **env, char *buf_size);
    void bad_exit_case(char *buf_size, int *built_in_value);
    void change_the_value_in_env(char ***env, int len_new_str,
    char *new_complete_str, char *command_with_eq_in_env);
    void change_var_in_env(char ***env, char **command);
    void free_command(char **command);
    void set_var_and_value(char ***env, char **command);
    void set_alone_var(char ***env, char **command);
    void error_handling(int wait_for_status, int *returned_value);
    void test_all_path_with_cmd(char **command_with_args,
    char ** possible_path, char *buf_size, char **env);
    void free_commands(char **command_with_args, char **possible_path, char
    *buf_size, char **env);
    void unsetenv_built_in(char ***env, char *buf_size);
    int unset_cmp(char const *s1, char const *s2, int n);
    void free_line_from_env(char ***env, char *command_eq, int *j);
    int few_args_case(char **args);
    void unset_command(char *command_eq, char **args, int i);
    int cd_commands(char **env, char *buf_size);
    int is_spaces_or_tabs(const char *str);
    int is_fifo(void);
    int is_a_sep(char c, char *separator);
    int count_words_in_args(char *str, char *separator);
    int count_words_options(char *str, char *separator);
    char **spliter_by_options(char *str, char *options);
    void end_of_the_word(char **array_words, int i, int *char_in_str,
    int *count);
    int my_array_length(char **array);
    void execute_cmd_by_cmd(char **env, char **new_formated_str,
    int *returned_value);
    int malloc_fd_and_create_pipe(int nb_cmds, int **fd);
    void redirections(int i, int nb_cmds, int **fd);
    void last_statement(int i, pipe_elem_t *pipe_elem, pid_t *pid,
    int *returned_value);
    int create_new_child(pid_t *pid, int i);
    void free_tab(int **command);
    int is_in_str(char *str);
    int clean_end_str(char const* str);
    int clean_start_str(char const* str);
    int invalid_null(char *new_splited_str);
    int one_cmd(char *new_splited_str, int *returned_value,
    pipe_elem_t *pipe_elem);
    int case_without_pipe(pipe_elem_t *pipe_elem, int *returned_value);
    int secondary_process(char **env, char *buf_size);
    int count_pipes(char *buf_size);

#endif /* !STR_LIB */

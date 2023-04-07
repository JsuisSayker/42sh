/*
** EPITECH PROJECT, 2023
** new_project_folder_file
** File description:
** mysh
*/

#ifndef MYSH_H_
    #define MYSH_H_
    #include <fcntl.h>
    #include <signal.h>
    #include <stdbool.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <sys/stat.h>
    #include <sys/wait.h>
    #include <unistd.h>
    #include "my_str.h"
    #include "my_int.h"
    #include "spliter_redirector.h"
    #define OK 0
    #define KO 84
    typedef struct mysh_s {
        pid_t pid;
        int action_built_in;
        int nb_field;
        char *buffer;
        char **env;
        int return_value;
        char **path_array;
        char **str_split;
        char ***command_split;
        char **redirector;
    }mysh_t;
    typedef struct fd_need_s{
        int index_pipe_fd;
        int nb_redirector;
        pid_t *all_pid;
        int **pipe_fd;
    }fd_need_t;
    int mysh(char ** env);
    int print_arg(char **arg);
    char **spliter(char *str, char const * const delimiter);
    int free_map(char **map);
    int my_map_len(char **map);
    int read_user_input(mysh_t *mysh_need);
    int built_in_function(mysh_t *mysh_need, fd_need_t *fd_need_n);
    void prompt(void);
    int change_directory(mysh_t *mysh_need);
    int binary_function(mysh_t *mysh_need, fd_need_t *fd_need_n);
    int my_str_cmp_begin(char const *s1, char const *s2);
    char * get_var_env(char **env, char * str);
    int switch_var_env(char **env, char *var, char *str);
    char **copy_env(char **env);
    void free_all(mysh_t *mysh_needs);
    int exit_function(mysh_t *mysh_need, fd_need_t *fd_need_n);
    int setenv_function(mysh_t *mysh_need, fd_need_t *fd_need_n);
    int unsetenv_function(char ***env, char **str_split);
    int env_function(mysh_t *mysh_need, fd_need_t *fd_need_n);
    int add_cmd_to_path(char **path_array, char *cmd);
    int str_contain_char(char *str, char c);
    char *pwd_function(void);
    char *add_equal(char *str);
    char *add_home_to_directory(char *str, char **env);
    int display_too_many_argument(char **str_split);
    int default_change_directory(mysh_t *mysh_need);
    void display_error(char **str_split, int return_cd);
    int home_change_directory(mysh_t *mysh_need);
    int previous_change_directory(mysh_t *mysh_need);
    int is_cmd(char const *s1, char const *s2);
    int intialize_struct_mysh_value(mysh_t *mysh_need, char **env);
    int str_only_contain_str(char *str, char *delimiter);
    int is_str_redirector(char * str);
    int child_function(mysh_t *mysh_need, fd_need_t *fd_need_n);
    void initialise_fd_need_structure(char ***command_split, fd_need_t\
    *fd_need_n);
    void free_child(mysh_t *mysh_need, fd_need_t *fd_need_n);
    int redirector_after_cmd(mysh_t *mysh_need, fd_need_t *fd_need_n);
    int redirector_before_cmd(mysh_t *mysh_need, fd_need_t *fd_need_n);
    char *generate_malloc_str_from_str(char const *const str);
    int free_command_split(char ***command_split);
    int launch_command(mysh_t *mysh_need, fd_need_t *fd_need_n);
    char *my_load_fd_in_memory(int const fd);
    int file_function(mysh_t *mysh_need, fd_need_t *fd_need_n);
    int ambiguous_output_redirect(mysh_t *mysh_need);
    int basic_ambiguous_output_redirect(mysh_t *mysh_need, char **redirector);
#endif /* !MYSH_H_ */

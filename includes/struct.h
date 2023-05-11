/*
** EPITECH PROJECT, 2023
** Minishell1
** File description:
** struct
*/

#ifndef STRUCT_H_
    #define STRUCT_H_

    typedef struct base_minishell_s {
        char **path;
        char **command;
        char ***p_command;
        char **env;
        char *pwd;
        int return_value;
        int yes_or_not;
        int exit;
    } base_minishell_t;

    typedef struct need_tab_s {
        int **fd;
        int fd_pos;
        int tab_pos_x;
        int tab_pos_y;
        int tab_len;
        int nbr_parameter;
        int redirect_arg;
        int aft_arg;
        char *left_redirector_str;
        int special_exec;
    } need_tab_t;

    typedef struct all_str_s {
        char **p_str;
        char *str;
        int len_str;
    } all_str_t;

    struct function {
        char *str;
        int (*proto)(base_minishell_t *, char **);
    };


#endif /* !STRUCT_H_ */

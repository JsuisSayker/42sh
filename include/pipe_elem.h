/*
** EPITECH PROJECT, 2023
** pipe_elem
** File description:
** pipe_elem
*/

#ifndef PI_PE
    #define PI_PE
    typedef struct pipe_elem{
        int **fd;
        int nb_cmds;
        char **env;
        char **splited_by_pipe;
    } pipe_elem_t;

#endif /* !PI_PE */

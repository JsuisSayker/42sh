/*
** EPITECH PROJECT, 2023
** Minishell2
** File description:
** struct_args_for_entry
*/

#ifndef STRUCT_ARGS_FOR_ENTRY_H_
    #define STRUCT_ARGS_FOR_ENTRY_H_

    typedef struct args_s{
        int invalide;
        int missing;
        int ambigous;
        int nbr_parameter;
    }args_s_t;

#endif /* !STRUCT_ARGS_FOR_ENTRY_H_ */

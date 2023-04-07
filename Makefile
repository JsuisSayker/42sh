##
## EPITECH PROJECT, 2023
## antman
## File description:
## Makefile
##

SRC			=	main.c\
				setenv.c\
				env_cpy.c\
				is_fifo.c\
				one_cmd.c\
				built_in.c\
				unset_cmp.c\
				exit_cases.c\
				path_finder.c\
				count_pipes.c\
				cd_commands.c\
				launch_shell.c\
				invalid_null.c\
				redirections.c\
				free_command.c\
				env_built_in.c\
				setup_substrs.c\
				free_commands.c\
				unset_command.c\
				set_alone_var.c\
				few_args_case.c\
				error_handling.c\
				last_statement.c\
				count_line_env.c\
				my_array_length.c\
				verify_null_cmd.c\
				is_substr_in_str.c\
				create_new_child.c\
				unsetenv_built_in.c\
				change_var_in_env.c\
				set_var_and_value.c\
				case_without_pipe.c\
				secondary_process.c\
				is_spaces_or_tabs.c\
				spliter_by_options.c\
				execute_cmd_by_cmd.c\
				free_line_from_env.c\
				exec_command_binaries.c\
				test_all_path_with_cmd.c\
				change_the_value_in_env.c\
				malloc_fd_and_create_pipe.c

DIR_SRC =       $(addprefix src/, $(SRC))

OBJ     =       $(DIR_SRC:.c=.o)

LDLIBS		=	-L ./lib/ -lmy_str -lmy_printf

CPPFLAGS	=	-I ./include/ -I ./lib/my_str/include\
-I ./lib/my_printf/include -ggdb3

CFLAGS		=	-Wall -Wextra

NAME	= 42sh

all: make_libs $(NAME)

make_libs:
	make -C lib/my_str
	make -C lib/my_printf

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(LDLIBS) $(CPPFLAGS) $(CFLAGS)

clean:
	make clean -C lib/my_str
	make clean -C lib/my_printf
	rm -f $(OBJ)

fclean: clean
	make fclean -C lib/my_str
	make fclean -C lib/my_printf
	rm -f $(NAME)

re:		fclean all

.PHONY: all clean fclean make_libs re

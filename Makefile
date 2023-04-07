##
## EPITECH PROJECT, 2023
## makefile
## File description:
## makefile
##

SRC			=	mysh.c												\
				prompt.c											\
				free_command_split.c								\
				free_map.c											\
				launch_command.c									\
				copy_env.c											\
				free_all.c											\
				add_equal.c											\
				my_map_len.c										\
				get_var_env.c										\
				pwd_function.c										\
				switch_var_env.c									\
				binary_function.c									\
				read_user_input.c									\
				add_cmd_to_path.c									\
				my_str_cmp_begin.c									\
				str_contain_char.c									\
				ambiguous_output_redirect.c							\
				basic_ambiguous_output_redirect.c					\
				add_home_to_directory.c								\
				is_cmd.c											\
				free_child.c										\
				initialise_fd_need_structure.c						\
				is_str_redirector.c									\
				generate_malloc_str_from_str.c						\
				child_function.c									\
				redirector_after_cmd.c								\
				redirector_before_cmd.c								\
				intialize_struct_mysh_value.c						\
				my_load_fd_in_memory.c								\
				file_function.c										\
				spliter_redirector/is_redirector.c					\
				spliter_redirector/count_nb_cell_of_array.c			\
				spliter_redirector/free_spliter.c					\
				spliter_redirector/spliter_redirector.c				\
				built_in_function/built_in_function.c				\
				built_in_function/print_arg.c						\
				built_in_function/exit.c							\
				built_in_function/setenv_function.c					\
				built_in_function/unsetenv_function.c				\
				built_in_function/env_function.c					\
				built_in_function/cd/change_directory.c				\
				built_in_function/cd/display_error.c				\
				built_in_function/cd/display_too_many_argument.c	\
				built_in_function/cd/home_change_directory.c		\
				built_in_function/cd/previous_change_directory.c	\
				built_in_function/cd/default_change_directory.c		\


DIR_SRC		=	$(addprefix src/, $(SRC))

MAIN_SRC	=	src/main.c

TEST		=	test_get_var_env.c									\
				test_add_cmd_to_path.c								\
				test_str_contain_char.c								\
				test_switch_var_env.c								\
				test_spliter_redirector.c							\
				test_count_nb_cell_of_array.c						\
				test_my_str_cmp_begin.c								\
				test_free_map.c										\
				test_is_cmd.c										\
				test_print_arg.c									\
				test_add_equal.c									\

DIR_TESTS	=	$(addprefix tests/, $(TEST))

OBJ_DIR_SRC	=	$(DIR_SRC:.c=.o)

OBJ_MAIN	=	$(MAIN_SRC:.c=.o)

OBJ			=	$(OBJ_DIR_SRC) $(OBJ_MAIN)

LDLIBS		=	-L lib/ -l my_str -l my_int -l my_linked_list

CPPFLAGS	=	-I include/\
				-I lib/my_str/include\
				-I lib/my_linked_list/include\
				-I lib/my_int/include\

NAME		=	mysh

all: make_libs $(NAME)

$(NAME):	lib/libmy_str.a lib/libmy_linked_list.a $(OBJ)
	gcc -o $(NAME) $(OBJ) $(LDLIBS) $(CPPFLAGS)

make_libs:
	make -C lib/my_str
	make -C lib/my_int
	make -C lib/my_linked_list

clean:
	make clean -C lib/my_str/
	make clean -C lib/my_int
	make clean -C lib/my_linked_list
	rm -f $(OBJ)

fclean: clean
	make fclean -C lib/my_str/
	make fclean -C lib/my_int
	make fclean -C lib/my_linked_list
	rm -rf unit_tests
	rm -f *.gcov
	rm -f vgcore*
	rm -f $(NAME)

re:		fclean all

unit_tests:	re
		mkdir unit_tests
		make unit_tests -C lib/my_str/
		gcc -o unit_tests/unit_tests $(DIR_SRC) $(DIR_TESTS)\
		$(CPPFLAGS) $(LDLIBS) --coverage -lcriterion

tests_run:	unit_tests
		make tests_run -C lib/my_str/
		./unit_tests/unit_tests

.PHONY: all clean fclean re make_libs tests_run

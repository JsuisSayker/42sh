##
## EPITECH PROJECT, 2023
## makefile
## File description:
## makefile
##

SRC			=	main.c					\
				minishell_one.c			\
				cd/move_in_folder.c		\
				cd/move_in_folder_sub.c	\
				cd/cd.c					\
				pwd_function.c			\

SRC_TOOLBOX	=	take_env.c						\
				take_entry.c					\
				starting.c						\
				parameter.c						\
				free.c							\
				my_load_fd_in_memory.c			\
				find_alias_of_the_command.c		\
				replace_alias_with_command.c	\
				replace_alias_with_parameter.c	\
				write_in_file.c					\
				clean_str.c						\
				tab_to_char.c					\
				take_parameter.c				\

SRC_TAB		=	reduce_tab.c					\
				enlarge_tab.c					\
				modif_or_add_array_to_tab.c		\
				check_parameter_and_modif_tab.c	\
				remove_of_tab.c					\
				entry_w_parameter_or_not.c		\
				append_str_to_file.c			\
				display_file.c					\
				append_cmd_to_history.c			\
				my_load_file_in_memory.c		\

SRC_COMMAND	=	command.c									\
				command_checker.c							\
				env.c										\
				unsetenv_setenv.c							\
				string_command.c							\
				child_display.c								\
				alias.c										\
				alias_sub.c									\
				history.c									\
				echo_command.c								\
				file_function/redirector.c					\
				file_function/left_redirector.c				\
				file_function/left_redirector_sub.c			\
				file_function/right_redirector.c			\
				with_parameter/function_build.c				\
				with_parameter/command_with_parameter.c		\
				with_parameter/duplicate_and_close_pipe.c	\
				with_parameter/function_build_checker.c		\
				display_error_command.c						\


SRC_ERROR	=	check_argc_argv.c				\
				check_pipe.c					\
				error_message_cmd.c				\
				error_message_parameter.c		\
				check_redirector_left.c			\
				check_redirector_right.c		\

DIR_SRC		=	$(addprefix src/, $(SRC))

DIR_TAB		=	$(addprefix src/tab/, $(SRC_TAB))

DIR_COMMAND	=	$(addprefix src/command/, $(SRC_COMMAND))

DIR_TOOLBOX	=	$(addprefix src/toolbox/, $(SRC_TOOLBOX))

DIR_ERROR	=	$(addprefix src/error_handing/, $(SRC_ERROR))

OBJ_SRC		=	$(DIR_SRC:.c=.o)

OBJ_TAB		=	$(DIR_TAB:.c=.o)

OBJ_COMMAND	=	$(DIR_COMMAND:.c=.o)

OBJ_TOOLBOX	=	$(DIR_TOOLBOX:.c=.o)

OBJ_ERROR	=	$(DIR_ERROR:.c=.o)

OBJ			=	$(OBJ_SRC) $(OBJ_TAB) $(OBJ_COMMAND) $(OBJ_ERROR) $(OBJ_TOOLBOX)

NAME		=	42sh

LDLIB		=	-L./lib/

LMY			=	-lmy

CPPFLAGS	=	-I./includes/ -ggdb3

CFLAGS		=	-Wall -Wextra

LCRITER		= -lcriterion

$(NAME): $(OBJ)
	make -C lib/my/
	gcc -o $@ $^ $(LDLIB) $(LMY) $(CFLAGS)

all: $(NAME)

debug : $(OBJ)
	make -C lib/my
	gcc -o $(NAME) $^ $(DEBUG) $(LDLIB) $(LMY)

clean:
	rm -f $(OBJ)
	make clean -C lib/my/

fclean: clean
	rm -f $(NAME)
	rm -f unit_tests*
	rm -f .history.txt
	rm -f .alias.txt
	make fclean -C lib/my/

re: fclean $(NAME)

unit_tests:	$(SRC)
	make -C lib/my/
	gcc -o unit_tests $^ tests/test.c $(LDLIB) $(LMY) $(CPPFLAGS) \
	--coverage -lcriterion
	./unit_tests
	gcovr --exclude tests/

.PHONY: all clean fclean re unit_tests

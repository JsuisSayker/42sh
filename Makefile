##
## EPITECH PROJECT, 2023
## makefile
## File description:
## makefile
##

SRC			=	main.c					\
				minishell_one.c			\
				cd/move_in_folder.c		\
				cd/cd.c

SRC_TOOLBOX	=	take_env.c		\
				take_entry.c	\
				starting.c		\
				parameter.c		\
				free.c

SRC_TAB		=	reduce_tab.c					\
				enlarge_tab.c					\
				modif_or_add_array_to_tab.c		\
				check_parameter_and_modif_tab.c	\
				remove_of_tab.c					\
				entry_w_parameter_or_not.c

SRC_COMMAND	=	command.c									\
				command_checker.c							\
				env.c										\
				unsetenv_setenv.c							\
				string_command.c							\
				child_display.c								\
				with_parameter/fonction_build.c				\
				with_parameter/command_with_parameter.c		\
				with_parameter/duplicate_and_close_pipe.c	\
				with_parameter/fonction_build_checker.c


SRC_ERROR	=	check_argc_argv.c				\
				check_pipe.c					\
				error_message_cmd.c				\
				error_message_for_redirector.c	\
				check_redirector.c

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

NAME		=	mysh

LDLIB		=	-L./lib/

LMY			=	-lmy

CPPFLAGS	=	-I./includes/ -ggdb3

LCRITER		= -lcriterion

$(NAME): $(OBJ)
	make -C lib/my/
	gcc -o $@ $^ $(LDLIB) $(LMY)

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
	make fclean -C lib/my/

re: fclean $(NAME)

unit_tests:	$(SRC)
	make -C lib/my/
	gcc -o unit_tests $^ tests/test.c $(LDLIB) $(LMY) $(CPPFLAGS) \
	--coverage -lcriterion
	./unit_tests
	gcovr --exclude tests/

.PHONY: all clean fclean re unit_tests

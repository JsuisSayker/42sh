##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## mon make file
##

SRC			=	my_str_to_word_array.c		\
				my_complexspliter.c			\
				my_splitstr.c				\
				my_str_isalpha_num.c		\
	  			my_putchar.c				\
	  			my_put_nbr.c				\
	  			my_putstr.c					\
	  			my_strcat.c					\
	  			my_strcmp.c					\
	  			my_strcpy.c					\
	  			my_str_isalpha.c			\
	  			my_str_isnum.c				\
	  			my_strlen.c					\
	  			my_strncmp.c				\
				char_to_int.c				\
				my_tabcpy.c					\
				my_tablen.c					\

OBJ			=	$(SRC:.c=.o)

NAME		=	libmy.a

CPPFLAGS	=	-I./include/ -Wall -Wextra -ggdb3

DEBUG		=	-ggdb3

all:	${NAME}

${NAME}:	${OBJ}
	ar rc $@ $^
	mv ${NAME} ../

debug: ${OBJ}
	ar rc ${NAME} $^ ${DEBUG}
	mv rc ${NAME} ../

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f ../$(NAME)

.PHONY: all clean fclean

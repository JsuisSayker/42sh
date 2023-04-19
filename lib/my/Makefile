##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## mon make file
##

SRC			=	my_str_to_word_array.c		\
				my_str_isalpha_num.c		\
				my_splitstr.c				\
				my_complexspliter.c			\
	  			my_strlen.c					\
				my_strncmp.c				\
				my_strcpy.c					\
				my_strcat.c					\
				my_str_isalpha.c			\
				my_tablen.c					\
				my_tabcpy.c

OBJ			=	$(SRC:.c=.o)

NAME		=	libmy.a

CPPFLAGS	=	-ggdb3

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	mv $(NAME) ../

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f ../$(NAME)

.PHONY: all clean fclean

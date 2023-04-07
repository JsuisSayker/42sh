##
## EPITECH PROJECT, 2023
## makefile of root
## File description:
## Makefile
##

SRC	=	my_di.c	\
		my_s.c	\
		my_pourcentage.c	\
		my_octal.c	\
		my_strlen.c	\
		my_putchar.c	\
		my_revstr.c	\
		my_x.c	\
		my_n.c	\
		my_strcat.c	\
		my_printf.c	\
		print_float.c	\
		my_round.c	\
		my_upper_x.c	\
		my_u.c	\
		my_e.c	\
		my_shift.c	\
		my_p.c	\
		my_c.c	\
		my_putstr.c	\
		my_putnbr.c	\
		my_e_precision.c	\
		my_f_precision.c	\
		my_point.c	\
		my_round_precision.c	\
		my_b.c

DIR_SRC =       $(addprefix src/, $(SRC))

OBJ     =       $(DIR_SRC:.c=.o)

CPPFLAGS	=	-I include

NAME	=	../libmy_printf.a

$(NAME):  $(OBJ)
	ar rc $(NAME) $(OBJ)

all:	$(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

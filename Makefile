NAME = libftprintf.a
FLAGS = -Wextra -Wall -Werror
SRC = \
	ft_print_char.c 	ft_print_hex.c		ft_print_num.c  \
	ft_print_str.c 		ft_print_unum.c		ft_printf.c 	ft_print_ptr.c
OBJ = $(SRC:%.c=%.o)

all : $(NAME)

$(NAME) : $(OBJ)

%.o : %.c ft_printf.h
	cc -c $(FLAGS) $< -o $@
	ar -rc $(NAME) $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : clean
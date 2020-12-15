##
## EPITECH PROJECT, 2018
## NAVY MAKEFILE
## File description:
## LIB MAKEFILE
##

AR 		= 	ar rc

NAME 	= 	../libmy.a

LIB_PATH		=	./include/
MY_PRINTF		=	./my_printf/
LIBPRINTF_PATH	=	$(MY_PRINTF)include/

SRC 	= 	$(MY_PRINTF)my_ascii_value.c 	\
			$(MY_PRINTF)my_binary.c 		\
			$(MY_PRINTF)my_hexa_x_upper.c 	\
			$(MY_PRINTF)my_hexa_x.c 		\
			$(MY_PRINTF)my_octal_arg.c 		\
			$(MY_PRINTF)my_pointer.c 		\
			$(MY_PRINTF)my_printf.c 		\
			$(MY_PRINTF)my_put_nbr_arg.c 	\
			$(MY_PRINTF)my_put_nbr_base.c 	\
			$(MY_PRINTF)my_putchar_arg.c 	\
			$(MY_PRINTF)my_putchar_modulo.c \
			$(MY_PRINTF)my_putstr_arg.c 	\
			free_tab.c						\
			my_alloc.c 						\
			my_isnum.c						\
			my_printab.c					\
			my_putchar.c 					\
			my_putstr.c 					\
			my_revstr.c 					\
			my_strcomp.c 					\
			my_strlen.c						\
			my_realloc.c					\
			my_strdup.c						\
			my_getnbr.c

OBJ 	= 	$(SRC:.c=.o)

override CFLAGS 	+= 	-W -Wall -Wextra -Werror -I $(LIB_PATH) -I $(LIBPRINTF_PATH)

LDFLAGS = 	-L. -lmy

$(NAME): $(OBJ)
	@echo -e "\n\nIT MAKES A LIB\n\n"
	$(AR) $(NAME) $(OBJ)

all: $(NAME)

clean:
	@rm -f $(OBJ)
	@rm -f *.gcda
	@rm -f *.gcno
	@rm -f ./my_printf/*.gcno
	@rm -f ./my_printf/*.gcda
	@rm -f core*
	@rm -f vgcore*

fclean: clean
	@rm -f ../$(NAME)
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

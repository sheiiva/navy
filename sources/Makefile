##
## EPITECH PROJECT, 2018
## NAVY MAKEFILE
## File description:
## SOURCES MAKEFILE
##

NAME 	= 	../navy
SRC_LIB = 	libsrc.a
CC		= 	gcc

SRC		=	attack.c			\
			check_args.c		\
			check_inputs.c		\
			check_map.c			\
			connect_players.c	\
			data_pinger.c		\
			free_struct.c 		\
			get_enemy_s_pid.c	\
			help.c				\
			main.c				\
			main_loop.c			\
			map_maker.c			\
			parser.c			\
			ping_counter.c		\
			wait.c

OBJ 	= 	$(SRC:.c=.o)

I_PATH				=	../include/
LIB_I_PATH			=	../lib/my/include/
LIB_PRINTF_I_PATH	=	../lib/my/my_printf/include/

override CFLAGS 	+= 	-W -Wall -Wextra -Werror -I$(I_PATH) -I$(LIB_I_PATH) -I$(LIB_PRINTF_I_PATH)
LDFLAGS = 	-L ../lib/ -lmy

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) $(CFLAGS)

$(SRC_LIB): $(OBJ)
	@echo -e "\n\nIT MAKES A SRC LIB\n\n"
	ar rc $(SRC_LIB) $(OBJ)

all: $(NAME)

lib: $(SRC_LIB)

clean:
	@rm -f $(OBJ)
	@rm -f *.gcda
	@rm -f *.gcno
	@rm -f core*
	@rm -f vgcore*

fclean: clean
	@rm -f libmy.a
	@rm -f $(NAME)
	@rm -f $(SRC_LIB)

re: fclean all

.PHONY: all clean fclean re

##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## make some files
##

CC 		= 	gcc

NAME 	= 	critests

SRC 	= 	critest_printf.c 		\
			critest_parser.c 		\
			critest_map_maker.c 	\
			critest_data_pinger.c	\
			critest_verif_map.c

OBJ 	= 	$(SRC:.c=.o)

I_PATH			=	./include/
SOURCE_I_PATH	=	./../include/	

CFLAGS 	=	-W -Wall -Wextra -g3 -I $(I_PATH) -I$(SOURCE_I_PATH) --coverage
LDFLAGS = 	-lcriterion -L ../sources -lsrc -L ../lib/ -lmy

$(NAME): $(OBJ)
	@make -C ../lib/my 'CFLAGS += --coverage' --no-print-directory
	@make lib -C ../sources 'CFLAGS += --coverage' --no-print-directory
	@$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS)
	@./$(NAME)

all: $(NAME)

clean:
	@rm -f $(OBJ)
	@rm -f *.gcda
	@rm -f *.gcno
	@rm -f core*
	@rm -f vgcore*

fclean: clean
	@rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re

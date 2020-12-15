##
## EPITECH PROJECT, 2018
## NAVY MAKEFILE
## File description:
## ROOT MAKEFILE
##

NAME 		= 	navy

GCV 		= 	gcovr
GCVNAME 	= 	coverage.html
GCVFLAGS 	= 	--html --html-details
GCVEXCLUDE 	= 	--exclude tests/

$(NAME):
	@make -C ./lib/my/ --no-print-directory
	@make -C ./sources --no-print-directory

all: $(NAME)

tests_run:
	@make -C ./tests --no-print-directory
	@echo -e "\n\n\n"
	@$(GCV) $(GCVEXCLUDE)
	@$(GCV) -r . $(GCVFLAGS) -o $(GCVNAME) $(GCVEXCLUDE)
	@echo -e "\n\n\n"

clean:
	@make clean -C ./lib/my/ --no-print-directory
	@make clean -C ./sources/ --no-print-directory
	@make clean -C ./tests/ --no-print-directory
	@rm -f *.html
	@rm -f vgcore*

fclean: clean
	@make fclean -C ./lib/my/ --no-print-directory
	@make fclean -C ./sources/ --no-print-directory
	@make fclean -C ./tests/ --no-print-directory
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

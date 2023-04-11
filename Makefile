##
## EPITECH PROJECT, 2023
## delivery
## File description:
## Makefile
##

OBJ     =     $(SRC:.c=.o)

SRC     =     main.c

NAME    =    chocolatine

all: $(NAME)

chocolatine: $(OBJ)
		gcc $(OBJ) -o $(NAME)
tests_run:
	@printf    "All test completed."

clean:
	rm -f $(OBJ)
	rm -f *~
	rm -f #~#

fclean: clean
	rm -f $(OBJ) chocolatine
re:     fclean all
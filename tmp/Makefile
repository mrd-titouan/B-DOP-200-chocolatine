##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile to compile C / C++ projects
## src / object / include / tests - repository for C, or
## Src / Object / Include / Tests - repository for C++
##

CC  		=	@gcc
CXX 		=	@g++

NAME		=	gameoflife

SRC 		=	src/main.c \
			src/utils.c \
			src/file.c \
			src/handling_error.c \
			src/error_case.c \
			src/my_second_str_to_word_array.c \
			src/count_neighbors.c \
			src/next_generation.c \

SRC_ALL 	=	$(shell find src -name '*.c')
OBJ 		=	$(patsubst src/%.c,object/%.o,$(SRC))
SRC-CRIT	=	$(wildcard $(addprefix tests/, *).c)
OBJ-CRIT	=	$(SRC-CRIT:.c=.o)

CPPFLAGS	+=	-g3 -Wall -Wextra -Wno-long-long
CFLAGS		+=	-I ./include/ -fno-builtin
CXXFLAGS	+=	-IInclude -fno-builtin
CRITFLAGS	=	-lcriterion --coverage

ECHO    	=	echo -e
DEFAULT 	=	"\033[0m"
BOLD_T  	=	"\033[1m"
DIM_T   	=	"\033[2m"
UNDLN_T 	=	"\033[4m"
BLACK_C 	=	"\033[30m"
RED_C   	=	"\033[31m"
GREEN_C 	=	"\033[32m"
YELLO_C 	=	"\033[33m"
BLUE_C  	=	"\033[34m"
MAGEN_C 	=	"\033[35m"
CYAN_C  	=	"\033[36m"
WHITE_C 	=	"\033[97m"
DEFAULT_C	=	"\033[39m"
LIGHT_GREY	=	"\033[37m"
DARK_GREY	=	"\033[90m"
LIGHT_RED	=	"\033[91m"
LIGHT_GREEN	=	"\033[92m"
LIGHT_YELLO	=	"\033[93m"
LIGHT_BLUE	=	"\033[94m"
LIGHT_MAGEN	=	"\033[95m"
LIGHT_CYAN	=	"\033[96m"

all: message $(NAME)

$(NAME): $(OBJ)
	@$(CC) -o $(NAME) $(OBJ)
	@$(ECHO) $(BOLD_T)$(GREEN_C)"\n[✔] COMPILED:" $(DEFAULT)$(LIGHT_GREEN) \
		"$(NAME)\n"$(DEFAULT) || \
		$(ECHO) $(BOLD_T)$(RED_C)"[✘] "$(UNDLN_T)"BUILD FAILED:" $(LIGHT_RED) \
		"$(NAME)\n"$(DEFAULT)

test_run:	all $(OBJ-CRIT)
	@$(CC) $(CFLAGS) $(CRITFLAGS) $(OBJ-CRIT) -ldl
	@$(ECHO) $(GREEN_C)"* * * * * COMPLETED * * * * *"$(DEFAULT)
	./a.out

clean:
	@find . -type f \( -iname "*~" \) -delete
	@$(RM) $(OBJ)
	@$(ECHO) $(RED_C)$(DIM_T)"[clean]  "$(DEFAULT) \
		$(BOLD_T)$(RED_C)"DELETED: "$(DEFAULT) \
		$(LIGHT_RED)"$(NAME)'s object files"$(DEFAULT)
	@$(RM) $(OBJ-CRIT)
	@$(RM) vgcore.*
	@$(ECHO) $(RED_C)$(DIM_T)"[clean]  "$(DEFAULT) \
		$(BOLD_T)$(RED_C)"DELETED: "$(DEFAULT) \
		$(LIGHT_RED)"Valgrind files"$(DEFAULT)

fclean:	clean
	@$(RM) $(NAME)
	@$(ECHO) $(RED_C)$(DIM_T)"[fclean] "$(DEFAULT) \
		$(BOLD_T)$(RED_C)"DELETED: "$(DEFAULT) \
		$(LIGHT_RED)"Binary $(NAME)"$(DEFAULT)

re:	fclean all

object/%.o: src/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<			\
	&& $(ECHO) $(GREEN_C)[OK]$(BOLD_T) $< $(DEFAULT)	\
	|| $(ECHO) $(RED_C)[KO]$(BOLD_T) $< $(DEFAULT)

Object/%.o:	Src/%.cpp
	@$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c -o $@ $<			\
	&& $(ECHO) $(GREEN_C)[OK]$(BOLD_T) $< $(DEFAULT)	\
	|| $(ECHO) $(RED_C)[KO]$(BOLD_T) $< $(DEFAULT)

gitignore:
	@$(ECHO) $(LIGHT_CYAN)$(BOLD_T)[STARTING GITIGNORE SETTINGS]$(DEFAULT) $<
	@$(ECHO)
	@touch .gitignore
	@$(ECHO) $(LIGHT_CYAN)$(BOLD_T)[ADDING]$(DEFAULT)$(GREEN_C) .gitignore $<
	@$(ECHO) .gitignore >> .gitignore
	@$(ECHO)
	@$(ECHO) $(LIGHT_CYAN)$(BOLD_T)[ADDING]$(DEFAULT)$(GREEN_C) .o $<
	@$(ECHO) *.o >> .gitignore
	@$(ECHO)
	@$(ECHO) $(LIGHT_CYAN)$(BOLD_T)[ADDING]$(DEFAULT)$(GREEN_C) .a $<
	@$(ECHO) *.a >> .gitignore
	@$(ECHO)
	@$(ECHO) $(LIGHT_CYAN)$(BOLD_T)[ADDING]$(DEFAULT)$(GREEN_C) .log $<
	@$(ECHO) *.log >> .gitignore
	@$(ECHO)
	@$(ECHO) $(LIGHT_CYAN)$(BOLD_T)[ADDING]$(DEFAULT)$(GREEN_C) .json $<
	@$(ECHO) *.json >> .gitignore
	@$(ECHO)
	@$(ECHO) $(LIGHT_CYAN)$(BOLD_T)[ADDING]$(DEFAULT)$(GREEN_C) .vscode $<
	@$(ECHO) *.vscode >> .gitignore
	@$(ECHO)
	@$(ECHO) $(LIGHT_CYAN)$(BOLD_T)[ADDING]$(DEFAULT)$(GREEN_C) vgcore. $<
	@$(ECHO) vgcore.* >> .gitignore
	@$(ECHO)
	@$(ECHO) $(LIGHT_CYAN)$(BOLD_T)[ADDING]$(DEFAULT)$(GREEN_C) .idea/ $<
	@$(ECHO) .idea/ >> .gitignore
	@$(ECHO)
	@$(ECHO) $(LIGHT_CYAN)$(BOLD_T)[ADDING]$(DEFAULT)$(GREEN_C) $(NAME) $<
	@$(ECHO) $(NAME) >> .gitignore
	@$(ECHO)
	@$(ECHO) $(LIGHT_CYAN)$(BOLD_T)[TERMINATED]$(DEFAULT) $<

abricot:
	@clear
	@$(LINE_RETURN)
	@$(ECHO) $(BOLD_T)$(GREEN_C)\
		"           ____   _____   _____   _____   ____   _______ "$(DEFAULT)
	@$(ECHO) $(BOLD_T)$(GREEN_C)\
		"    /\    |  _ \ |  __ \ |_   _| / ____| / __ \ |__   __|"$(DEFAULT)
	@$(ECHO) $(BOLD_T)$(GREEN_C)\
		"   /  \   | |_) || |__) |  | |  | |     | |  | |   | |   "$(DEFAULT)
	@$(ECHO) $(BOLD_T)$(GREEN_C)\
		"  / /\ \  |  _ < |  _  /   | |  | |     | |  | |   | |   "$(DEFAULT)
	@$(ECHO) $(BOLD_T)$(GREEN_C)\
		" / ____ \ | |_) || | \ \  _| |_ | |____ | |__| |   | |   "$(DEFAULT)
	@$(ECHO) $(BOLD_T)$(GREEN_C)\
		"/_/    \_\|____/ |_|  \_\|_____| \_____| \____/    |_|   "$(DEFAULT)
	@$(LINE_RETURN)
	@abricot --all --ignore --nofunc
	@$(ECHO) $(GREEN_C)[TERMINÉ]$(BOLD_T) $< $(DEFAULT)

message:
	@$(LINE_RETURN)
	@$(ECHO) $(BOLD_T)$(GREEN_C)" ____        _ _     _  "$(DEFAULT)
	@$(ECHO) $(BOLD_T)$(GREEN_C)"| __ ) _   _(_) | __| | "$(DEFAULT)
	@$(ECHO) $(BOLD_T)$(GREEN_C)"|  _ \| | | | | |/ _\` |"$(DEFAULT)
	@$(ECHO) $(BOLD_T)$(GREEN_C)"| |_) | |_| | | | (_| | "$(DEFAULT)
	@$(ECHO) $(BOLD_T)$(GREEN_C)"|____/ \__,_|_|_|\__,_| "$(DEFAULT)
	@$(LINE_RETURN)

.PHONY: all build_libs test_run clean_libs clean fclean re gitignore \
		abricot message
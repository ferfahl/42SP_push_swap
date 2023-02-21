################################################################################
##                               42 PUSH SWAP                                 ##
################################################################################

#static library's name
NAME =		push_swap
B_NAME =	push_swap_bonus

#colors
RESET 			:= \033[0m
GREEN			=	\e[32m
RED				=	\e[91m
YELLOW			=	\e[033m
BLUE			=	\e[34m

#printing
LOG   			:= printf "[$(GREEN)INFO$(RESET)] %s\n"

################################################################################
##                                DIRECTORIES                                 ##
################################################################################

#scr functions
MANDATORY_FILES =	01_main.c \
					02_check.c \
					03_init.c \
					04_stack.c \
					05_moves.c \
					06_double_moves.c \
					errors.c \
					test.c \
					utils.c \
					utils_libft.c \

BONUS_FILES =

#directories
OBJPATH =			temps
MANDATORY_PATH =	sources
BONUS_PATH =		bonus
LIBFT_PATH =		./libft
LIBFT =				$(LIBFT_PATH)/libft.a

#header to libft.h
INCLUDE =	-I ./ -I $(LIBFT_PATH)

################################################################################
##                                 COMPILATION                                ##
################################################################################

#compiling
CC =	gcc
FLAGS =	-Wall -Werror -Wextra -g3
GDB =	gdb
VAL =	valgrind --leak-check=full --track-origins=yes
## --trace-children=yes --track-fds=yes

# clean
RM =		-rm -f
RM_DIR =	rm -rf

#tranform into .o
OBJ_MANDATORY = $(MANDATORY_FILES:%.c=$(OBJPATH)/%.o)
OBJ_BONUS = $(BONUS_FILES:%.c=$(OBJPATH)/%.o)

NUMBER_OF_FILES	=	$(words $(MANDATORY_FILES))
PROGRESS			=	0

################################################################################
##                                    RULES                                   ##
################################################################################

#make
all: $(OBJPATH) $(NAME)

#make bonus
bonus: $(OBJPATH) $(B_NAME)

##folder for temporary objects
$(OBJPATH):
		@mkdir -p $(OBJPATH)
		@$(LOG) "Creating objects directory"

##make libft
$(LIBFT):
		@$(LOG) "Compiling Libft..."
		@make -C $(LIBFT_PATH) --no-print-directory

##rule name - make push_swap
$(NAME): $(LIBFT)  $(OBJ_MANDATORY)
		cc $(FLAGS) -o $(NAME) $(OBJ_MANDATORY) $(LIBFT)

##rule name - make push_swap_bonus
$(B_NAME): $(LIBFT)  $(OBJ_BONUS)
		cc $(FLAGS) -o $(B_NAME) $(OBJ_BONUS) $(LIBFT)

##compile MANDATORY
$(OBJPATH)/%.o: $(MANDATORY_PATH)/%.c $(HEADER)
		cc $(FLAGS) -c $< -o $@ $(INCLUDE)
		@echo -n "$(YELLOW)Compiling $(RESET)$$(( $(PROGRESS) * 100 / $(NUMBER_OF_FILES)))%\r"
		$(eval PROGRESS=$(shell echo $$(($(PROGRESS)+1))))

##compile BONUS
$(OBJPATH)/%.o: $(BONUS_PATH)/%.c $(HEADER)
		cc $(FLAGS) -c $< -o $@ $(INCLUDE)

#make mem -> mcheck
mem:
		$(VAL) ./$(NAME) "42", "598", "1", "-987", "411", "42"

#make clean -> remove objects
clean:
		@$(LOG) "Removing Libft"
		@make clean -C $(LIBFT_PATH) --no-print-directory
		@$(LOG) "Removing objects"
		@$(RM) $(OBJ_MANDATORY) $(OBJ_BONUS)

#make fclean -> remove all
fclean: clean
		@make fclean -C $(LIBFT_PATH) --no-print-directory
		@$(LOG) "Removing executable"
		@$(RM) $(NAME) $(B_NAME)
		@$(LOG) "Removing objects directory"
		@$(RM_DIR) $(OBJPATH)

#make re -> clear all and recompliles
re:		fclean all
		@$(LOG) "Recompiled succesfully"

##avoids double inclusion
.PHONY: all clean fclean re bonus

#make norm -> verify norm
norm:
		@clear
		@norminette ${MANDATORY_FILES} ${INCDIR}* | grep Error || true

#make git m="message" -> commit to git
git:
		git add .
		git commit -m "$(m)"
		git push

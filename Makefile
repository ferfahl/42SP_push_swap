#####################INPUTS#####################

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

#static library's name
NAME =		push_swap
B_NAME =	push_swap_bonus

#directories
OBJPATH =			temps
MANDATORY_PATH =	sources
BONUS_PATH =		bonus
LIBFT_PATH =		./libft
LIBFT =				$(LIBFT_PATH)/libft.a

#header to libft.h
INCLUDE =	-I ./ -I $(LIBFT_PATH)

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

#####################RULES#####################

#make
all: $(OBJPATH) $(NAME)

#make bonus
bonus: $(OBJPATH) $(B_NAME)

#make folder for temps
$(OBJPATH):
		@mkdir -p $(OBJPATH)

#make libft
$(LIBFT):
		@echo "Compiling Libft..."
		@make -C $(LIBFT_PATH) --no-print-directory

#rule name - make push_swap
$(NAME): $(LIBFT)  $(OBJ_MANDATORY)
		cc $(FLAGS) -o $(NAME) $(OBJ_MANDATORY) $(LIBFT)

#rule name - make push_swap_bonus
$(B_NAME): $(LIBFT)  $(OBJ_BONUS)
		cc $(FLAGS) -o $(B_NAME) $(OBJ_BONUS) $(LIBFT)

#compile MANDATORY
$(OBJPATH)/%.o: $(MANDATORY_PATH)/%.c $(HEADER)
		cc $(FLAGS) -c $< -o $@ $(INCLUDE)

#compile BONUS
$(OBJPATH)/%.o: $(BONUS_PATH)/%.c $(HEADER)
		cc $(FLAGS) -c $< -o $@ $(INCLUDE)

#mcheck
mem:
		$(VAL) ./$(NAME) "42", "598", "1", "-987", "411", "42"

#remove objects
clean:
		make clean -C $(LIBFT_PATH)
		$(RM) $(OBJ_MANDATORY) $(OBJ_BONUS)

#remove all
fclean: clean
		make fclean -C $(LIBFT_PATH)
		$(RM) $(NAME) $(B_NAME) $(RM_DIR) $(OBJPATH)

#clear all
re: fclean all

#avoids double inclusion
.PHONY: all clean fclean re bonus

git:
		git add .
		git commit -m "$(m)"
		git push

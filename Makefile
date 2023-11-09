# VARIABLE DECLARATION ############################################################################

NAME =			push_swap

CC =			gcc

CFLAGS =		-Wall -Werror -Wextra

HEADERS =		./includes

BLACK	= 		\033[0;30m
RED		= 		\033[0;91m
GREEN	= 		\033[0;92m
YELLOW	= 		\033[0;93m
BLUE	= 		\033[0;94m
PURPLE	= 		\033[0;35m
CYAN	= 		\033[0;96m
WHITE	= 		\033[0;37m

SRCS =			srcs/main.c \
				srcs/sort.c \
				srcs/sort_utils.c \
				srcs/check_errors.c \
				srcs/create_stack.c \
				srcs/swap_functions.c \
				srcs/convert_char_to_int.c \

LIB = 			lib/libft.a \

LIBFT_PATH = 	./libft/
LIBFT_LIB = 	libft.a
MAKE_LIBFT = 	$(addprefix $(LIBFT_PATH), $(LIBFT_LIB))

OBJS =			$(SRCS:.c=.o)

# RULES ###########################################################################################

all: $(NAME)

$(MAKE_LIBFT): force
	make -C ./libft

$(NAME): $(OBJS) $(MAKE_LIBFT)
	echo "$(CYAN)Compiling Push_swap :$(WHITE)"
	$(CC) $(CFLAGS) $(OBJS) $(MAKE_LIBFT) -o $(NAME)
	echo "$(GREEN)Push_swap successfully compiled ! \n\n$(WHITE)"

./srcs/%.o: ./srcs/%.c $(HEADERS)/push_swap.h $(MAKE_LIBFT)
	$(CC) $(CFLAGS) -I$(HEADERS) -c $< -o $@

clean:
	echo "$(YELLOW)Deleting all files exept 'all.a' and binaries$(WHITE)"
	rm -rf $(OBJS) $(OBJS_BONUS)
	make clean -C $(LIBFT_PATH)

fclean: clean
	echo "$(PURPLE)Deleting all files 'all.a' and binaries$(WHITE)"
	rm -rf $(NAME) $(NAME_BONUS) lib
	make fclean -C $(LIBFT_PATH)

re: fclean all


force:

# .SILENT:

.PHONY: all clean fclean make_lib libft force re

NAME_MAN := push_swap
NAME_BONUS := checker
DIR_INC := ./include

LIBFTNAME := libft.a
LIBFTDIR := ./libft

CC := cc
CFLAGS := -Wall -Wextra -Werror -I$(DIR_INC)

SRC_MAN := calc_rots.c main.c ord.c parse.c print_rots.c p_s_movs.c push_best.c rots_movs.c\
	sort_3.c stack_utils.c
DIR_MAN := mandatory/
SRC_MAN := $(addprefix $(DIR_MAN), $(SRC_MAN))
OBJ_MAN := $(SRC_MAN:.c=.o)

SRC_BONUS := checker_bonus.c ord_bonus.c parse_bonus.c p_s_movs_bonus.c rots_movs_bonus.c\
	stack_utils_bonus.c
DIR_BONUS := bonus/
SRC_BONUS := $(addprefix $(DIR_BONUS), $(SRC_BONUS))
OBJ_BONUS := $(SRC_BONUS:.c=.o)

all: $(NAME_MAN)

$(NAME_MAN): $(OBJ_MAN) $(LIBFTDIR)/$(LIBFTNAME)
	@$(CC) $(CFLAGS) $(OBJ_MAN) $(LIBFTDIR)/$(LIBFTNAME) -o $(NAME_MAN)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BONUS) $(LIBFTDIR)/$(LIBFTNAME)
	@$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIBFTDIR)/$(LIBFTNAME) -o $(NAME_BONUS)

$(LIBFTDIR)/$(LIBFTNAME):
	@make -C $(LIBFTDIR) CFLAGS="$(CFLAGS)"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make -C libft clean
	@rm -f $(OBJ_MAN) $(OBJ_BONUS) $(LIBFTDIR)/$(LIBFTNAME)

fclean: clean
	@make clean
	@rm -f $(NAME_MAN) $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re bonus
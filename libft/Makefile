NAME := libft.a
PROJECTS := subject subject_bonus extra ft_printf ft_gnl
INC_DIR := ./include

CC := cc
CFLAGS := -Werror -Wextra -Wall -I$(INC_DIR)
AR = ar -rcs

all: $(PROJECTS) $(NAME)

$(NAME):
	@$(AR) $(NAME) $(shell find . -type f -name "*.o")

build:
	@$(AR) $(NAME) $(shell find . -type f -name "*.o")

subject: $(patsubst %.c, %.o, $(wildcard ./subject/mandatory/*.c))

subject_bonus: subject $(patsubst %.c, %.o, $(wildcard ./subject/bonus/*.c))

extra: $(patsubst %.c, %.o, $(wildcard ./extra/*.c))

ft_printf: subject $(patsubst %.c, %.o, $(wildcard ./ft_printf/mandatory/*.c))

ft_gnl: subject $(patsubst %.c, %.o, $(wildcard ./ft_gnl/mandatory/*.c))

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@find . -type f -name "*.o" -delete

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all build clean fclean re subject subject_bonus extra ft_printf ft_gnl

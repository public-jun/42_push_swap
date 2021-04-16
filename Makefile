NAME_CH := checker
# NAME_PS := push_swap

CC := gcc
CFLAGS := -Wall -Wextra -Werror

LIBFT_DIR = ./libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

SRCS_CH := srcs/checker.c \
			srcs/utils.c
# SRCS_PS :=

OBJCS_CH := $(SRCS_CH:%.c=%.o)
# OBJCS_PS := $(SRCS_PS:%.c=%.o)

INCLUDE := ./includes

RM := rm -f

# all: $(NAME_CH) $(NAME_PS)
all: $(NAME_CH)


$(NAME_CH): $(OBJCS_CH) $(LIBFT_LIB)
	$(CC) $(CFLAGS) $(OBJCS_CH) $(LIBFT_LIB) -I $(INCLUDE) -o $(NAME_CH)

$(LIBFT_LIB): $(LIBFT_DIR)
	$(MAKE) -C $(LIBFT_DIR) bonus

# $(NAME_PS): $(OBJCS_PS)
# 	$(CC) $(CFLAGS) $(OBJCS_PS) $(LIBFT_LIB) -I $(INCLUDE) -o $(NAME_CH)


clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(RM) $(OBJCS_CH)

fclean:clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(NAME_CH)

re:fclean all

testch:
	$(CC) -g $(CFLAGS) $(SRCS_CH) $(LIBFT_LIB) -I $(INCLUDE) -o $(NAME_CH)

# testps:
# 	$(CC) -g $(CFLAGS) $(SRCS_PS) $(LIBFT_LIB) -I $(INCLUDE) -o $(NAME_CH)

.PHONY: all clean flcean re testch

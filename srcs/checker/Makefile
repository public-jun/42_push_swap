NAME := checker

CC := gcc
CFLAGS := -Wall -Wextra -Werror

LIBFT_DIR := ../../libft
LIBFT_LIB := $(LIBFT_DIR)/libft.a

COMMON_DIR := ../common
COMMON_LIB := $(COMMON_DIR)/libcommon.a

SRCS_CH := ./checker.c \
			./get_next_line.c \
			./get_next_line_utils.c \
			./read_instruction.c \
			./check_correct_order.c

OBJCS_CH := $(SRCS_CH:%.c=%.o)

INCLUDE := ../../includes

RM := rm -f

all: $(NAME)

$(NAME): $(OBJCS_CH) $(LIBFT_LIB) $(COMMON_LIB)
	$(CC) $(CFLAGS) $(OBJCS_CH) $(LIBFT_LIB) $(COMMON_LIB) -I $(INCLUDE) -o $(NAME)

$(LIBFT_LIB): $(LIBFT_DIR)
	$(MAKE) -C $(LIBFT_DIR) bonus

$(COMMON_LIB): $(COMMON_DIR)
	$(MAKE) -C $(COMMON_DIR)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(COMMON_DIR) clean
	$(RM) $(OBJCS_CH)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(COMMON_DIR) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

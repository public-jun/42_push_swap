NAME := push_swap

CC := gcc
CFLAGS := -Wall -Wextra -Werror

LIBFT_DIR := ../../libft
LIBFT_LIB := $(LIBFT_DIR)/libft.a

COMMON_DIR := ../common
COMMON_LIB := $(COMMON_DIR)/libcommon.a

SRCS_PS := ./push_swap.c \
			./quick_sort.c \
			./sort_only_3_node.c \
			./sort_over5.c \
			./exit_ps.c \
			./instr_optimazation.c \

OBJCS_PS := $(SRCS_PS:%.c=%.o)

INCLUDE := ../../includes

RM := rm -f

all: $(NAME)

$(NAME): $(OBJCS_PS) $(LIBFT_LIB) $(COMMON_LIB)
	$(CC) $(CFLAGS) $(OBJCS_PS) $(LIBFT_LIB) $(COMMON_LIB) -I $(INCLUDE) -o $(NAME)

$(LIBFT_LIB): $(LIBFT_DIR)
	$(MAKE) -C $(LIBFT_DIR) bonus

$(COMMON_LIB): $(COMMON_DIR)
	$(MAKE) -C $(COMMON_DIR)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(COMMON_DIR) clean
	$(RM) $(OBJCS_PS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(COMMON_DIR) fclean
	$(RM) $(NAME)

re: fclean all

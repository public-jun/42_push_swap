NAME := push_swap

CC := gcc
CFLAGS := -Wall -Wextra -Werror

LIBFT_DIR := ../../libft
LIBFT_LIB := $(LIBFT_DIR)/libft.a

COMMON_DIR := ../common
COMMON_LIB := $(COMMON_DIR)/libcommon.a

SRCS_PS := ./main.c \
			./debug.c \
			./exec_instr.c \
			./exit_ps.c \
			./init_info.c \
			./instr_optimization.c \
			./option_v.c \
			./print_ans.c \
			./quick_sort.c \
			./set_pair_info.c \
			./sort_less6.c \
			./sort_only_3_node1.c \
			./sort_only_3_node2.c \
			./sort_over5_first_part.c \
			./sort_over5_half_stack.c \
			./sort_over5_latter_part.c \
			./sort_over5_utils.c \
			./utils.c \
			./utils2.c \

OBJCS_PS := $(SRCS_PS:%.c=%.o)

INCLUDE := ../../includes

RM := rm -f

all: $(NAME)

$(NAME): $(OBJCS_PS) $(LIBFT_LIB) $(COMMON_LIB)
	$(CC) $(CFLAGS) -I $(INCLUDE) $(OBJCS_PS) $(LIBFT_LIB) $(COMMON_LIB) -o $(NAME)

.c.o:
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@

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

testps:
	$(MAKE) -C $(LIBFT_DIR)
	$(CC) -g $(CFLAGS) $(SRCS_PS) $(COMMON_DIR)/*.c $(LIBFT_LIB) -I $(INCLUDE) -o $(NAME)

.PHONY: all clean fclean re

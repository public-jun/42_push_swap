NAME_CH := checker
NAME_PS := push_swap

CC := gcc
CFLAGS := -Wall -Wextra -Werror

LIBFT_DIR = ./libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

COMMON_DIR = ./srcs/common
COMMON_LIB = $(COMMON_DIR)/libcommon.a

CH_DIR := ./srcs/checker

PS_DIR := ./srcs/push_swap

SRCS_CH := $(CH_DIR)/checker.c \
			$(CH_DIR)/get_next_line.c \
			$(CH_DIR)/get_next_line_utils.c \
			$(CH_DIR)/read_instruction.c \
			$(CH_DIR)/check_correct_order.c


SRCS_PS := $(PS_DIR)/push_swap.c \
			$(PS_DIR)/quick_sort.c \
			$(PS_DIR)/sort_only_3_node.c \
			$(PS_DIR)/sort_over5.c \
			$(PS_DIR)/exit_ps.c \
			$(PS_DIR)/instr_optimazation.c \


OBJCS_CH := $(SRCS_CH:%.c=%.o)
OBJCS_PS := $(SRCS_PS:%.c=%.o)

INCLUDE := ./includes

RM := rm -f

all: $(NAME_CH) $(NAME_PS)


$(NAME_CH): $(OBJCS_CH) $(LIBFT_LIB) $(COMMON_LIB)
	$(CC) $(CFLAGS) $(OBJCS_CH) $(LIBFT_LIB) $(COMMON_LIB) -I $(INCLUDE) -o $(NAME_CH)

$(NAME_PS): $(OBJCS_PS) $(LIBFT_LIB) $(COMMON_LIB)
	$(CC) $(CFLAGS) $(OBJCS_PS) $(LIBFT_LIB) $(COMMON_LIB) -I $(INCLUDE) -o $(NAME_PS)

$(LIBFT_LIB): $(LIBFT_DIR)
	$(MAKE) -C $(LIBFT_DIR) bonus

$(COMMON_LIB): $(COMMON_DIR)
	$(MAKE) -C $(COMMON_DIR)



clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(COMMON_DIR) clean
	$(RM) $(OBJCS_CH) $(OBJCS_PS)

fclean:clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(COMMON_DIR) fclean
	$(RM) $(NAME_CH) $(NAME_PS)

re: fclean all

testch:
	$(CC) -g $(CFLAGS) $(SRCS_CH) $(COMMON_DIR)/*.c $(LIBFT_LIB) -I $(INCLUDE) -I $(COMMON_DIR)/common.h -o $(NAME_CH)

testps:
	$(CC) -g $(CFLAGS) $(SRCS_PS) $(COMMON_DIR)/*.c $(LIBFT_LIB) -I $(INCLUDE) -I $(COMMON_DIR)/common.h -o $(NAME_PS)

.PHONY: all clean flcean re testch

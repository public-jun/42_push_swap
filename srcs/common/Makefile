NAME := libcommon.a

SRCS := add_node.c \
		add_instr_node.c \
		branch_by_instr.c \
		exit.c \
		init_list.c \
		instructions.c \
		utils.c

OBJCS := $(SRCS:%.c=%.o)

CC := gcc

CFLAGS = -Wall -Wextra -Werror

INCLUDE = ../../includes

RM := rm -f

AR := ar

ARFLAGS = rc

$(NAME): $(OBJCS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJCS)

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDE)

all: $(NAME)

clean:
	$(RM) $(OBJCS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

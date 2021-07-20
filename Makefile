NAME =  $(PUSH_SWAP)
PUSH_SWAP := push_swap
CHECKER := checker

CC := gcc
CFLAGS := -Wall -Wextra -Werror

LIBFT_DIR := ./libft
LIBFT_LIB := $(LIBFT_DIR)/libft.a

COMMON_DIR := ./srcs/common
COMMON_LIB := $(COMMON_DIR)/libcommon.a

CH_DIR := ./srcs/checker
PS_DIR := ./srcs/push_swap

INCLUDE := ./includes

RM := rm -rf

all: $(NAME)

$(CHECKER):
	$(MAKE) -C $(CH_DIR)
	cp $(CH_DIR)/$(CHECKER) ./

$(PUSH_SWAP):
	$(MAKE) -C $(PS_DIR)
	cp $(PS_DIR)/$(PUSH_SWAP) ./


clean:
	$(MAKE) -C $(CH_DIR) clean
	$(MAKE) -C $(PS_DIR) clean

fclean:
	$(MAKE) -C $(CH_DIR) fclean
	$(MAKE) -C $(PS_DIR) fclean
	$(RM) $(CHECKER) $(CHECKER).dSYM $(PUSH_SWAP) $(PUSH_SWAP).dSYM

bonus: $(CHECKER)

re: fclean all

testch:
	$(MAKE) -C $(LIBFT_DIR)
	$(CC) -g $(CFLAGS) $(CH_DIR)/*.c $(COMMON_DIR)/*.c $(LIBFT_LIB) -I $(INCLUDE) -o $(CHECKER)

testps:
	$(MAKE) -C $(LIBFT_DIR)
	$(CC) -g $(CFLAGS) $(PS_DIR)/*.c $(COMMON_DIR)/*.c $(LIBFT_LIB) -I $(INCLUDE) -o $(PUSH_SWAP)

test:
	$(MAKE) -C $(CH_DIR) testch
	cp $(CH_DIR)/$(CHECKER) ./
	$(MAKE) -C $(PS_DIR) testps
	cp $(PS_DIR)/$(PUSH_SWAP) ./

valgrindpush_swap: testps
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --errors-for-leak-kinds=all --error-exitcode=666 ./$(PUSH_SWAP) 1 0 -1

valgrindchecker: testch
	valgrind --leak-check=full --show-leak-kinds=all --errors-for-leak-kinds=all --error-exitcode=666 ./$(CHECKER)

.PHONY: all clean flcean bonus  re testch testps valgrindpush_swap valgrindchecker

# -*- Makefile -*-

NAME := push_swap

CFLAGS := -Wall -Wextra -Werror 

CC := gcc

SRCS := \
src/actions_p.c \
src/actions_r.c \
src/actions_rr.c \
src/actions_s.c \
src/binary.c \
src/errorcheck.c \
src/main.c \
src/sort.c \
src/sort_hardcode.c \
src/sort_radix.c \
src/free_stacks.c \
src/test.c

HEADFILES := src/push_swap.h
LIBFT := libft/libft.a

all : $(NAME)

$(NAME) : $(SRCS) $(LIBFT)
	$(CC) -o $@ $^

$(LIBFT) :
	$(MAKE) -C libft

clean :
	$(MAKE) clean -C libft

fclean :
	$(MAKE) fclean -C libft
	rm -f $(NAME) $^

re : fclean all

.PHONY: all, clean, fclean, re

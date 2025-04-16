# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lusimon <lusimon@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/14 18:08:50 by lusimon           #+#    #+#              #
#    Updated: 2025/03/03 19:40:13 by lusimon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -Werror -g

# Header files
HEADERS = push_swap.h

# Source files
SRCS = algorithm/stack_a/define_target.c algorithm/stack_a/prep_push_a_to_b.c \
algorithm/initialize_stack.c algorithm/sort_stack.c algorithm/sort_three.c \
algorithm/stack_b_comeback.c algorithm/stack_utils.c \
arguments/handle_arguments.c arguments/multiple_arguments_checks.c arguments/single_argument_checks.c \
libft/bonus_libft.c libft/ft_split.c libft/libft.c \
rules/push.c rules/reverse_rotate.c rules/rotate.c rules/swap.c \
main.c

# Object files (replace .c with .o). Compiling source files to object files
OBJS = $(SRCS:.c=.o)

# Delivery files
DELIVERY_FILES = $(NAME)

# Phony targets
.PHONY: all clean fclean re

# Rule for creating object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Default target
all: $(NAME)

# Create the library
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

# Clean up object files
clean:
	rm -f $(OBJS)

# Clean up object files and the library
fclean: clean
	rm -f $(NAME)

# Rebuild the library
re: fclean all

valgrind: re
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME)

# Specify what happens when the Makefile is executed
help:
	@echo "Makefile for $(NAME)"
	@echo "Usage:"
	@echo "  make          Build the project"
	@echo "  make clean    Remove object files"
	@echo "  make fclean   Remove object files and the library"
	@echo "  make re       Rebuild the project"
	@echo "  make help     Display this help message"
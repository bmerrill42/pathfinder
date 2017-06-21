# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpan <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/31 18:58:43 by tpan              #+#    #+#              #
#    Updated: 2017/05/31 20:00:24 by tpan             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ft_printf.a

CC		= gcc
CFLAGS 	= -Wall -Wextra -Werror
LIBFT = ../libft/libft.a
DEBUGFLAGS = -fsanitize=address -g -o ft_printf_debug
LEAKCHECK = -g -o ft_printf_leakcheck

SRCS =					read_flags.c \
						read_precision.c \
						read_width.c \
						read_length.c \
						read_specifier.c \
						app_wchar_width.c \
						apply_precision.c \
						apply_prefix.c \
						apply_width.c \
						compatible_flags.c \
						ft_printf.c \
						ft_vprintf.c \
						write_chars.c \
						write_conversion_substring.c \
						write_hex.c \
						write_octal.c \
						write_signed_int.c \
						write_unsigned_int.c \
						write_wchars.c \
						verify_flag_compatibility.c \
						fix_sign.c \

SRC = $(addprefix $(SRCDIR),$(SRCS))
OBJ = $(addprefix $(OBJDIR),$(SRCS:.c=.o))

OBJDIR = ./obj/
SRCDIR = ./srcs/
LIBDIR = ./../libft/
INCDIR = ./includes/

.PHONY: all, clean, fclean, re

all:$(LIBFT) $(NAME)

$(OBJ): $(SRC)
	@$(CC) $(CFLAGS) -c -I$(INCDIR) $(SRC)
	@mkdir -p $(OBJDIR)
	@mv $(SRCS:.c=.o) $(OBJDIR)

$(NAME): $(LIBFT) $(OBJ)
	@echo "Compiling ft_printf"
	@ar rc $(NAME) $(OBJ) $(LIBFT)
	@echo "Made ft_printf"

$(LIBFT):
	make -C $(LIBDIR) all

clean:
	@echo "Cleaning ft_printf"
	@rm -rf $(OBJDIR)
	@rm -rf ft_printf_debug
	@rm -rf ft_printf_debug.dSYM
	@rm -rf ft_printf_leakcheck
	@rm -rf ft_printf_leakcheck.dSYM
	@make -C $(LIBDIR) clean

fclean: clean
	@echo "Fclean ft_printf"
	@rm -rf $(NAME)
	@make -C $(LIBDIR) fclean

re: fclean all 

debug : $(LIBFT)
	@echo "Compiling ft_printf with debugging options"
	$(CC) $(SRC) $(LIBFT) -I$(INCDIR) $(DEBUGFLAGS)

leakcheck : $(LIBFT)
	@echo "Compiling ft_printf with valgrind options"
	$(CC) $(SRC) $(LIBFT) -I$(INCDIR) $(LEAKCHECK)


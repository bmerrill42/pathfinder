# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpan <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/03 19:55:55 by tpan              #+#    #+#              #
#    Updated: 2017/06/27 01:12:01 by bmerrill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = lem-in
CC = gcc
LIBFT = ./libft/libft.a
FT_PRINTF = ./ft_printf/ft_printf.a
CFLAGS = -Wall -Werror -Wextra
DEBUGFLAGS = -fsanitize=address -g
LEAKCHECK = -g
SRCFILES = 	parse.c error.c parse_main_functions.c parse_storage_functions.c lem_in.c solve.c print_ants.c connections.c init.c parse_helpers.c\

SRC = $(addprefix $(SRCDIR),$(SRCFILES))
OBJ = $(addprefix $(OBJDIR),$(SRCFILES:.c=.o))

OBJDIR = ./obj/
SRCDIR = ./srcs/
LIBFTDIR = ./libft/
FTPFDIR = ./ft_printf/
INCDIR = ./includes/

.PHONY:$(NAME), all, clean, fclean, re



all: $(LIBFT) $(FT_PRINTF) $(NAME)

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c -I$(INCDIR) $(SRC)
	mkdir -p $(OBJDIR)
	mv *.o $(OBJDIR)

$(NAME): $(LIBFT) $(FT_PRINTF) $(INCDIR)*.h $(OBJ)
	echo "Compiling Lem_in"
	$(CC) $(CFLAGS) -g -c -I$(INCDIR) $(SRC)
	mv *.o $(OBJDIR)
	$(CC) $(CFLAGS) -g -I$(INCDIR) -I$(LIBFTDIR) $(OBJ) $(LIBFT) $(FT_PRINTF) -o $@
	echo "Lem_in: Compiled"

$(LIBFT):
	make -C $(LIBFTDIR) all

$(FT_PRINTF): $(LIBFT)
	make -C $(FTPFDIR) all

clean:
	echo "Cleaning push_swap"
	rm -rf $(OBJDIR)
	rm -rf push_swap_debug
	rm -rf push_swap_debug.dSYM
	rm -rf push_swap_leakcheck
	rm -rf push_swap_leakcheck.dSYM
	rm -rf checker_debug
	rm -rf checker_debug.dSYM
	rm -rf checker_leakcheck
	rm -rf checker_leakcheck.dSYM
	make -C $(LIBFTDIR) clean
	make -C $(FTPFDIR) clean

fclean: clean
	echo "FCleaning push_swap"
	rm -rf $(NAME) checker
	make -C $(LIBFTDIR) fclean
	make -C $(FTPFDIR) fclean

re: fclean all

debug: $(LIBFT) $(FT_PRINTF)
	echo "Compiling push_swap with debugging options"
	$(CC) $(CFLAGS) $(SRC) $(PSMAIN) $(LIBFT) $(FT_PRINTF) -I$(INCDIR) $(DEBUGFLAGS) -o push_swap_debug
	$(CC) $(CFLAGS) $(SRC) $(CMAIN) $(LIBFT) $(FT_PRINTF) -I$(INCDIR) $(DEBUGFLAGS) -o checker_debug
	echo "Compiled push_swap debug"

leakcheck: $(LIBFT) $(FT_PRINTF)
	echo "Compiling for leak checks with valgrind"
	$(CC) $(CFLAGS) $(SRC) $(PSMAIN) $(LIBFT) $(FT_PRINTF) -I$(INCDIR) $(LEAKCHECK) -o push_swap_leakcheck
	$(CC) $(CFLAGS) $(SRC) $(CMAIN) $(LIBFT) $(FT_PRINTF) -I$(INCDIR) $(LEAKCHECK) -o checker_leakcheck
	echo "Compiled push_swap with leakchecker"

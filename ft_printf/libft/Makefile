# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpan <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/31 18:58:43 by tpan              #+#    #+#              #
#    Updated: 2017/03/21 15:01:55 by tpan             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

CC 	= -c -Wall -Wextra -Werror

SRC 	= ft_strlen.c ft_strncpy.c ft_strcpy.c \
		  ft_strcmp.c ft_putchar.c ft_putstr.c \
		  ft_atoi.c ft_tolower.c ft_isalpha.c \
		  ft_toupper.c ft_isdigit.c ft_isalnum.c\
		  ft_isprint.c ft_isascii.c ft_strdup.c \
		  ft_memset.c ft_bzero.c ft_strstr.c \
		  ft_memcmp.c ft_memcpy.c ft_memmove.c \
		  ft_memccpy.c ft_memchr.c ft_strcat.c \
		  ft_strncat.c ft_strchr.c ft_strrchr.c \
		  ft_putendl.c ft_putchar_fd.c ft_putstr_fd.c \
		  ft_putnbr.c ft_putnbr_fd.c ft_putendl_fd.c \
		  ft_strclr.c ft_memalloc.c ft_memdel.c \
		  ft_strnew.c ft_strdel.c ft_strncmp.c \
		  ft_strequ.c ft_strnequ.c ft_strlcat.c \
		  ft_strnstr.c ft_striteri.c ft_striter.c \
		  ft_strmap.c ft_strndup.c ft_strjoin.c \
		  ft_strmapi.c ft_isspace.c ft_strtrim.c \
		  ft_strsplit.c ft_wordlength.c ft_wordcount.c \
		  ft_lstnew.c ft_lstdelone.c ft_itoa.c \
		  ft_lstdel.c ft_lstiter.c ft_lstmap.c \
		  ft_strsub.c ft_lstadd.c ft_isnegative.c \
		  ft_reverse.c ft_realloc.c ft_utf8charencode.c \
		  ft_utf8charsize.c ft_utf8strencode.c ft_utf8strnencode.c\
		  ft_wchar_memset.c ft_wcharbits.c ft_wcharsize_utf8.c \
		  ft_wctomb.c ft_wstrcpy.c ft_wstrdup.c ft_wstrlen.c \
		  ft_wstrndup.c ft_wstrnsize_utf8.c ft_wstrsize_utf8.c \
		  ft_ishex.c ft_itoa_base.c ft_itoa_base_intmax.c \
		  ft_itoa_base_uintmax.c ft_itoa_base_ull.c ft_nbrlen.c \
		  ft_tolower_str.c ft_toupper_str.c \

OBJ 	= $(SRC:.c=.o)
	
.PHONY: $(NAME), all, clean, fclean, re

all: $(NAME)

$(NAME): 
	gcc $(SRC) $(CC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME) 

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)
	/bin/rm -f libft.h.gch
re: fclean all 

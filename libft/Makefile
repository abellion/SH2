# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abellion <abellion@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/10 11:25:27 by abellion          #+#    #+#              #
#    Updated: 2015/05/08 19:42:42 by abellion         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_C =	src/str/ft_strchr.c \
		src/str/ft_strrchr.c \
		src/str/ft_bzero.c \
		src/str/ft_strcmp.c \
		src/str/ft_strstr.c \
		src/str/ft_strcpy.c \
		src/str/ft_tolower.c \
		src/str/ft_toupper.c \
		src/str/ft_strnew.c \
		src/str/ft_strdel.c \
		src/str/ft_strclr.c \
		src/str/ft_striter.c \
		src/str/ft_striteri.c \
		src/str/ft_strmap.c \
		src/str/ft_strmapi.c \
		src/str/ft_strequ.c \
		src/str/ft_strnequ.c \
		src/str/ft_strsub.c \
		src/str/ft_strjoin.c \
		src/str/ft_strcjoin.c \
		src/str/ft_strtrim.c \
		src/str/ft_strsplit.c \
		src/str/ft_itoa.c \
		src/str/ft_strlcat.c \
		src/str/ft_strncat.c \
		src/str/ft_strdup.c \
		src/str/ft_strlen.c \
		src/str/ft_strncmp.c \
		src/str/ft_strncpy.c \
		src/str/ft_strcat.c \
		src/str/ft_strnstr.c \
		src/str/ft_atoi.c \
		src/str/ft_atos.c \
		\
		src/mem/ft_memccpy.c \
		src/mem/ft_memchr.c \
		src/mem/ft_memmove.c \
		src/mem/ft_memset.c \
		src/mem/ft_memcmp.c \
		src/mem/ft_memcpy.c \
		src/mem/ft_memalloc.c \
		src/mem/ft_memdel.c \
		\
		src/tab/ft_tablen.c \
		src/tab/ft_tabdup.c \
		src/tab/ft_tabdel.c \
		\
		src/ctype/ft_isalpha.c \
		src/ctype/ft_isalnum.c \
		src/ctype/ft_isascii.c \
		src/ctype/ft_isdigit.c \
		src/ctype/ft_isprint.c \
		\
		src/io/ft_putchar.c \
		src/io/ft_putstr.c \
		src/io/ft_putendl.c \
		src/io/ft_putnbr.c \
		src/io/ft_putchar_fd.c \
		src/io/ft_putchar_fd.c \
		src/io/ft_putstr_fd.c \
		src/io/ft_putendl_fd.c \
		src/io/ft_putnbr_fd.c \
		\
		src/lst/ft_lstadd.c \
		src/lst/ft_lstdel.c \
		src/lst/ft_lstdelone.c \
		src/lst/ft_lstiter.c \
		src/lst/ft_lstmap.c \
		src/lst/ft_lstnew.c \
		src/lst/ft_lstpop.c \
		src/lst/ft_lstcount.c \
		src/lst/ft_lstdup.c \

OBJ = $(patsubst %.c, %.o, $(notdir $(SRC_C)))

SOFT_NAME = libft

ARCHIVE_NAME = libft.a

C_G = $(shell echo "\033[0;32m")

C_END = $(shell echo "\033[0m")

all: $(SOFT_NAME)

$(SOFT_NAME):
	@echo "\n$(C_G)	==========	SOFTWARE COMPILATION	==========$(C_END)"
	gcc -g -c $(SRC_C) -Wall -Werror -Wextra
	@echo "\n$(C_G)	==========	CREATING ARCHIVE FILE	==========$(C_END)"
	ar rc $(ARCHIVE_NAME) $(OBJ)
	@echo "\n$(C_G)	==========	INDEXING ARCHIVE FILE	==========$(C_END)"
	ranlib $(ARCHIVE_NAME)

clean:
	@echo "\n$(C_G)	==========	DELETING OBJECTS FILES	==========$(C_END)"
	rm -rf $(OBJ)

fclean: clean
	@echo "\n$(C_G)	==========	DELETING ARCHIVE FILE	==========$(C_END)"
	rm -rf $(ARCHIVE_NAME)

re: fclean all

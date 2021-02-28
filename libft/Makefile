# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chde-mar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/10 11:54:49 by chde-mar          #+#    #+#              #
#    Updated: 2019/12/10 16:09:57 by chde-mar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC =	./ft_atoi.c ./ft_bzero.c ./ft_calloc.c ./ft_isalnum.c ./ft_isalpha.c\
		./ft_isascii.c ./ft_isdigit.c ./ft_isprint.c ./ft_memccpy.c\
		./ft_memchr.c ./ft_memcmp.c ./ft_memcpy.c ./ft_memmove.c ./ft_memset.c\
		./ft_putchar.c ./ft_putchar_fd.c ./ft_putendl.c ./ft_putendl_fd.c\
		./ft_putnbr.c ./ft_putnbr_fd.c ./ft_putstr.c ./ft_putstr_fd.c\
		./ft_strchr.c ./ft_strdup.c ./ft_strjoin.c ./ft_strlcpy.c ./ft_strlen.c\
		./ft_strncmp.c ./ft_strnstr.c ./ft_strrchr.c ./ft_substr.c ./ft_swap.c\
		./ft_tolower.c ./ft_toupper.c ./ft_strnew.c ./ft_split.c ./ft_itoa.c\
		./ft_strtrim.c ./ft_strmapi.c ./ft_strlcat.c


OBJECT =./ft_atoi.o ./ft_bzero.o ./ft_calloc.o ./ft_isalnum.o ./ft_isalpha.o\
		./ft_isascii.o ./ft_isdigit.o ./ft_isprint.o ./ft_memccpy.o\
		./ft_memchr.o ./ft_memcmp.o ./ft_memcpy.o ./ft_memmove.o ./ft_memset.o\
		./ft_putchar.o ./ft_putchar_fd.o ./ft_putendl.o ./ft_putendl_fd.o\
		./ft_putnbr.o ./ft_putnbr_fd.o ./ft_putstr.o ./ft_putstr_fd.o\
		./ft_strchr.o ./ft_strdup.o ./ft_strjoin.o ./ft_strlcpy.o ./ft_strlen.o\
		./ft_strncmp.o ./ft_strnstr.o ./ft_strrchr.o ./ft_substr.o ./ft_swap.o\
		./ft_tolower.o ./ft_toupper.o ./ft_strnew.o ./ft_split.o ./ft_itoa.o\
		./ft_strtrim.o ./ft_strmapi.o ./ft_strlcat.o


FLAGS = -Wall -Wextra -Werror
OPTIONS = -c -I ./includes/

all: $(NAME)

$(NAME):
	@echo "Compiling..."
	@gcc $(FLAGS) $(OPTIONS) $(SRC)
	@ar rc $(NAME) $(OBJECT) libft.h
	@echo "Done."

clean:
	@echo "Removing object files..."
	@/bin/rm -f $(OBJECT)
	@echo "Done."

fclean: clean
	@echo "Removing library..."
	@/bin/rm -f $(NAME)
	@echo "Done."

re: fclean all

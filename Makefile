# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chde-mar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/25 16:48:44 by chde-mar          #+#    #+#              #
#    Updated: 2021/02/25 16:48:47 by chde-mar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCS_LIST = \
		ft_printf.c \
		ft_printf_functions_1.c \
		ft_printf_functions_2.c \
		ft_printf_tab.c \
		ft_printf_char.c \
		ft_printf_str.c \
		ft_printf_num.c \
		ft_printf_unsigned.c \
		ft_printf_hex.c \
		ft_printf_precent.c \
		ft_printf_address.c

SRCS			= $(addprefix ${FOLDER}/, ${SRCS_LIST})
OBJS			= ${SRCS:.c=.o}
HEADER			= include
FOLDER			= srcs
LIBFT 			= libft
CC				= clang
CFLAGS 			= -Wall -Wextra -Werror
RM				= rm -f

all:			${NAME}
$(NAME):		${OBJS}
				@make -C $(LIBFT)
				@cp libft/libft.a ./$(NAME)
				@ar rcs $(NAME) $(OBJS)
bonus:			${NAME}
%.o: %.c
				@${CC} ${CFLAGS} -I ${HEADER} -o $@ -c $<
clean:
				@${RM} ${OBJS}
				@make clean -C $(LIBFT)
fclean:			clean
				@${RM} ${NAME}
				@make fclean -C $(LIBFT)
re:				fclean all
.PHONY: 		all fclean clean re

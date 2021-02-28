/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chde-mar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 10:41:53 by chde-mar          #+#    #+#             */
/*   Updated: 2021/02/26 00:16:41 by chde-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

# include "../libft/libft.h"

typedef struct	s_printf
{
	long int	min_width;
	int			p_dot;
	int			p_star;
	int			p_null;
	int			minus;
	int			zero;
	int			conversion;
	int			check_minus;
	char		*add_minus;
	char		*add_ox;
}				t_printf;

int				is_conversion(char c);
int				length_handler(t_printf *tab, char *str);
int				width_handler(t_printf *tab, int len);
char			*with_minus(char *str, int len, char *temp, t_printf *tab);
char			*without_minus(char *str, int len, char *temp, t_printf *tab);
char			*precision_handler(t_printf *tab, char *str, int len);
int				reset_tab(t_printf *tab);
int				p_to_tab(t_printf *tab, char **fmt, va_list *args, int width);
int				attributes_to_tab(t_printf *tab, char **fmt);
int				min_width_t(t_printf *tab, char **fmt, va_list *args, int d);
int				precent_min_width(t_printf *tab, int len);
char			*hex_handler(t_printf *tab, va_list *args, int h_base);
char			*min_width_and_minus(t_printf *tab, int len, char *new);
char			*ft_utoa_hex(unsigned int n, int base);
int				add_remove_minus(t_printf *tab, int len, char *new);
char			*cut_minus(char *str, t_printf *tab, char *new);
char			*add_minus_1(char *str, int len, t_printf *tab);
char			*add_minus_2(char *str1, t_printf *tab, char *temp);
int				unsigned_print(int len, t_printf *tab, char *str);
int				write_without_conv(char c);
char			*ft_ultoa_hex(unsigned long n, int base);
int				handlers(t_printf *tab, char *new, int str_size);
char			*ft_malloc(int size);
int				ft_free(char **str, int ret);
int				ft_printf(const char *format, ...);
int				parse(char *fmt, va_list *args);
int				conversions(t_printf *tab, va_list *args);
int				parse_precent(t_printf *tab, va_list *args, char *fmt);
int				validate_format(char *fmt);
int				ft_printf_char(t_printf *tab, va_list *args);
int				ft_printf_str(t_printf *tab, va_list *args);
int				ft_printf_unsigned(t_printf *tab, va_list *args);
int				ft_printf_hex_lowercase(t_printf *tab, va_list *args);
int				ft_printf_hex_uppercase(t_printf *tab, va_list *args);
int				ft_printf_precent(t_printf *tab);
int				ft_printf_num(t_printf *tab, va_list *args);
int				ft_printf_address(t_printf *tab, va_list *args);

#endif

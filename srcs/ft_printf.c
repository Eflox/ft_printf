/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chde-mar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 09:29:08 by chde-mar          #+#    #+#             */
/*   Updated: 2021/02/26 00:05:06 by chde-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				validate_format(char *fmt)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	if (!fmt)
		return (-1);
	while (fmt[j] != '\0')
	{
		if (fmt[j] == '%' && i == 0)
			i = 1;
		else if (is_conversion(fmt[j]) && i == 1)
			i = 0;
		j++;
	}
	if (i == 1)
		return (0);
	return (1);
}

int				parse_precent(t_printf *tab, va_list *args, char *fmt)
{
	char		*first;
	int			digit;

	digit = 0;
	first = NULL;
	first = fmt;
	reset_tab(tab);
	attributes_to_tab(tab, &fmt);
	min_width_t(tab, &fmt, args, digit);
	if (*fmt == '.')
		p_to_tab(tab, &fmt, args, digit);
	tab->conversion = *fmt++;
	return (fmt - first);
}

int				conversions(t_printf *tab, va_list *args)
{
	if (tab->conversion == 'c')
		return (ft_printf_char(tab, args));
	else if (tab->conversion == 's')
		return (ft_printf_str(tab, args));
	else if (tab->conversion == 'x')
		return (ft_printf_hex_lowercase(tab, args));
	else if (tab->conversion == 'X')
		return (ft_printf_hex_uppercase(tab, args));
	else if (tab->conversion == 'd')
		return (ft_printf_num(tab, args));
	else if (tab->conversion == 'i')
		return (ft_printf_num(tab, args));
	else if (tab->conversion == 'p')
		return (ft_printf_address(tab, args));
	else if (tab->conversion == '%')
		return (ft_printf_precent(tab));
	else if (tab->conversion == 'u')
		return (ft_printf_unsigned(tab, args));
	else if (!(is_conversion(tab->conversion)))
		return (-1);
	else
		return (0);
}

int				parse(char *fmt, va_list *args)
{
	int			i;
	int			j;
	int			args_count;
	int			args_parse;
	t_printf	tab;

	args_count = 0;
	i = 0;
	j = 0;
	while (fmt[i] != '\0')
	{
		if (fmt[i] == '%')
		{
			args_parse = parse_precent(&tab, args, fmt + i + 1);
			if ((j = conversions(&tab, args)) == (-1))
				return (-1);
			args_count = args_count + j;
			i = i + args_parse;
		}
		else
			args_count = args_count + write_without_conv(fmt[i]);
		i++;
	}
	return (args_count);
}

int				ft_printf(const char *format, ...)
{
	va_list		args;
	int			args_count;
	char		*fmt;

	fmt = (char *)format;
	if (!validate_format(fmt))
		return (0);
	va_start(args, format);
	if ((args_count = parse(fmt, &args)) == (-1))
		return (-1);
	va_end(args);
	return (args_count);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chde-mar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 13:14:46 by chde-mar          #+#    #+#             */
/*   Updated: 2021/02/26 00:18:18 by chde-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		min_width_t(t_printf *tab, char **fmt, va_list *args, int d)
{
	while (**fmt != '.' && !is_conversion(**fmt))
	{
		if (ft_isdigit(**fmt))
		{
			d = (d * 10) + (**fmt - '0');
			tab->min_width = d;
		}
		else if (**fmt == '*')
		{
			d = va_arg(*args, int);
			tab->min_width = d;
		}
		else
			break ;
		(*fmt)++;
	}
	return (1);
}

int		attributes_to_tab(t_printf *tab, char **fmt)
{
	while (**fmt == '-' || **fmt == '0' || **fmt == ' ')
	{
		if (**fmt == '-')
			tab->minus = 1;
		else if (**fmt == '0')
			tab->zero = 1;
		(*fmt)++;
	}
	return (1);
}

int		p_to_tab(t_printf *tab, char **fmt, va_list *args, int width)
{
	int	k;

	k = 0;
	while (!is_conversion(**fmt))
	{
		if (**fmt == '*')
		{
			width = va_arg(*args, int);
			tab->p_star = width;
			if (width == (-1))
				k = 1;
		}
		else if (ft_isdigit(**fmt))
		{
			width = (width * 10) + (**fmt - '0');
			tab->p_dot = width;
		}
		(*fmt)++;
	}
	if ((tab->p_dot == (-1)) && (tab->p_star == (-1)) && (k == 0))
		tab->p_null = 1;
	return (1);
}

int		reset_tab(t_printf *tab)
{
	tab->min_width = 0;
	tab->p_dot = -1;
	tab->p_star = -1;
	tab->p_null = -1;
	tab->minus = 0;
	tab->zero = 0;
	tab->conversion = 0;
	tab->check_minus = 0;
	tab->add_minus = "-";
	tab->add_ox = "0x";
	return (1);
}

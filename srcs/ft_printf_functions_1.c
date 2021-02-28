/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_functions_1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chde-mar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 13:12:58 by chde-mar          #+#    #+#             */
/*   Updated: 2021/02/26 00:07:06 by chde-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				is_conversion(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
			|| c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (c);
	return (0);
}

int				length_handler(t_printf *tab, char *str)
{
	int			len;

	len = ft_strlen(str);
	if ((tab->p_dot == 0) && (str[0] == '0'))
		len = 0;
	if ((tab->p_star == 0) && (str[0] == '0'))
		len = 0;
	if ((tab->p_null == 1) && (str[0] == '0'))
		len = 0;
	return (len);
}

int				width_handler(t_printf *tab, int len)
{
	if (!tab->min_width)
		tab->min_width = len;
	if (tab->min_width < 0)
	{
		tab->min_width = (tab->min_width * -1);
		tab->minus = 1;
	}
	if ((len > tab->min_width) && (tab->min_width > 0))
		tab->min_width = len;
	if (tab->check_minus && (tab->min_width > len))
		tab->min_width -= 1;
	if (tab->p_dot > 0 || tab->p_star > 0)
		tab->zero = 0;
	if ((tab->p_null == 1) && tab->zero)
		tab->zero = 0;
	if (tab->p_dot == 0 || tab->p_star == 0)
		tab->zero = 0;
	return (1);
}

char			*with_minus(char *str, int len, char *temp, t_printf *tab)
{
	int			i;

	i = 0;
	while (i < len)
	{
		str[i] = temp[i];
		i++;
	}
	while (i < tab->min_width)
	{
		if (tab->zero)
			str[i] = '0';
		else
			str[i] = ' ';
		i++;
	}
	return (str);
}

char			*without_minus(char *str, int len, char *temp, t_printf *tab)
{
	int			i;

	i = tab->min_width;
	while (i-- > 0 && len-- > 0)
		str[i] = temp[len];
	if (tab->zero)
	{
		while (i >= 0)
		{
			str[i] = '0';
			i--;
		}
	}
	return (str);
}

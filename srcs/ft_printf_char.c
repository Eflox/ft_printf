/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chde-mar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 09:29:08 by chde-mar          #+#    #+#             */
/*   Updated: 2021/02/26 00:06:18 by chde-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_printf_char(t_printf *tab, va_list *args)
{
	unsigned char	c;
	char			*str;

	str = NULL;
	c = va_arg(*args, int);
	if (!tab->min_width)
		tab->min_width = 1;
	if (tab->min_width < 0)
	{
		tab->min_width = (tab->min_width * -1);
		tab->minus = 1;
		tab->zero = 0;
	}
	if (!(str = ft_malloc(tab->min_width)))
		return (-1);
	if (tab->minus)
		str[0] = c;
	else
		str[tab->min_width - 1] = c;
	write(1, str, tab->min_width);
	ft_free(&str, 1);
	return (tab->min_width);
}

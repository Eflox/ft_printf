/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_precent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chde-mar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 12:56:50 by chde-mar          #+#    #+#             */
/*   Updated: 2021/02/26 00:11:10 by chde-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				precent_min_width(t_printf *tab, int len)
{
	if (tab->min_width)
		tab->min_width = len;
	if (tab->min_width < 0 && (tab->minus || tab->zero))
	{
		tab->min_width = (tab->min_width * -1);
		tab->minus = 1;
		tab->zero = 0;
	}
	if (len > tab->min_width)
		tab->min_width = len;
	if (tab->check_minus && (tab->min_width > len))
		tab->min_width -= 1;
	return (1);
}

int				ft_printf_precent(t_printf *tab)
{
	char		*str;
	char		*new;
	int			str_size;

	new = "%";
	str = NULL;
	str_size = 1;
	precent_min_width(tab, str_size);
	if (!(str = ft_malloc(tab->min_width)))
		return (-1);
	if (tab->minus)
		str = with_minus(str, str_size, new, tab);
	else
		str = without_minus(str, str_size, new, tab);
	write(1, str, ft_strlen(str));
	ft_free(&str, 1);
	return (tab->min_width);
}

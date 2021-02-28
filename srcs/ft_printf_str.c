/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflox <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 17:55:00 by eflox             #+#    #+#             */
/*   Updated: 2021/02/26 00:11:25 by chde-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf_str(t_printf *tab, va_list *args)
{
	char	*str;
	char	*temp;
	int		str_size;

	temp = (char *)va_arg(*args, const char *);
	if (!temp)
		temp = "(null)";
	else if (tab->p_null > 0)
		temp = "";
	str_size = ft_strlen(temp);
	if ((tab->p_dot > (-1)) && (tab->p_dot < str_size))
		str_size = tab->p_dot;
	else if ((tab->p_star > (-1)) && (tab->p_star < str_size))
		str_size = tab->p_star;
	width_handler(tab, str_size);
	if (!(str = ft_malloc(tab->min_width)))
		return (-1);
	if (tab->minus)
		with_minus(str, str_size, temp, tab);
	else
		without_minus(str, str_size, temp, tab);
	write(1, str, tab->min_width);
	ft_free(&str, 1);
	return (tab->min_width);
}

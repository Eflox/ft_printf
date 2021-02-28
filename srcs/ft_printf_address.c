/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_address.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chde-mar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 19:06:16 by chde-mar          #+#    #+#             */
/*   Updated: 2021/02/26 00:06:00 by chde-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char					*ft_ultoa_hex(unsigned long n, int base)
{
	unsigned long int	tmpn;
	int					len;
	char				*str;
	char				*hex;

	str = NULL;
	hex = NULL;
	hex = "0123456789abcdef";
	tmpn = n;
	len = 2;
	while (tmpn /= base)
		len++;
	if (!(str = (char*)malloc(sizeof(char) * len)))
		return (NULL);
	str[--len] = '\0';
	while (len--)
	{
		if (base == 16)
			str[len] = hex[n % base];
		else
			str[len] = n % base + '0';
		n = n / base;
	}
	return (str);
}

int						handlers(t_printf *tab, char *new, int str_size)
{
	char				*str;

	str_size = length_handler(tab, new);
	width_handler(tab, str_size);
	if (!(str = ft_malloc(tab->min_width)))
		return (-1);
	if (tab->minus)
		str = with_minus(str, str_size, new, tab);
	else
		str = without_minus(str, str_size, new, tab);
	write(1, str, ft_strlen(str));
	ft_free(&new, 1);
	ft_free(&str, 1);
	return (0);
}

int						ft_printf_address(t_printf *tab, va_list *args)
{
	unsigned long		u;
	char				*str;
	char				*temp;
	int					h_base;
	int					str_size;

	h_base = 16;
	u = va_arg(*args, unsigned long);
	if (!(str = ft_ultoa_hex(u, h_base)))
		return (-1);
	temp = str;
	if (!(str = ft_strjoin(tab->add_ox, str)))
		return (-1);
	ft_free(&temp, 1);
	str_size = ft_strlen(str);
	if (tab->p_dot > str_size || tab->p_star > str_size)
	{
		temp = str;
		if (!(str = precision_handler(tab, str, str_size)))
			return (-1);
		ft_free(&temp, 1);
	}
	if (handlers(tab, str, str_size) == -1)
		return (-1);
	return (tab->min_width);
}

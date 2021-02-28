/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chde-mar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 17:32:01 by chde-mar          #+#    #+#             */
/*   Updated: 2021/02/26 00:09:27 by chde-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				*ft_utoa_hex(unsigned int n, int base)
{
	long int		tmpn;
	int				len;
	char			*str;
	char			*hex;

	hex = "0123456789abcdef";
	str = NULL;
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

char				*min_width_and_minus(t_printf *tab, int len, char *new)
{
	char			*str;

	len = length_handler(tab, new);
	width_handler(tab, len);
	if (!(str = ft_malloc(tab->min_width)))
		return (NULL);
	if (tab->minus)
		str = with_minus(str, len, new, tab);
	else
		str = without_minus(str, len, new, tab);
	free(new);
	return (str);
}

char				*hex_handler(t_printf *tab, va_list *args, int h_base)
{
	unsigned int	u;
	char			*temp;
	char			*new;
	char			*str;
	int				str_size;

	u = va_arg(*args, unsigned int);
	if (!(new = ft_utoa_hex(u, h_base)))
		return (NULL);
	str_size = ft_strlen(new);
	if ((tab->min_width < 0) && tab->zero)
		tab->zero = 0;
	if (tab->p_dot > str_size || tab->p_star > str_size)
	{
		temp = new;
		if (!(new = precision_handler(tab, new, str_size)))
			return (NULL);
		ft_free(&temp, 1);
	}
	if (!(str = min_width_and_minus(tab, str_size, new)))
		return (NULL);
	return (str);
}

int					ft_printf_hex_uppercase(t_printf *tab, va_list *args)
{
	char			*str;
	int				i;
	int				h_base;

	i = 0;
	h_base = 16;
	if (!(str = hex_handler(tab, args, h_base)))
		return (-1);
	while (str[i] != '\0')
	{
		if (str[i] >= 97 && str[i] <= 122)
			str[i] -= 32;
		i++;
	}
	write(1, str, ft_strlen(str));
	ft_free(&str, 1);
	return (tab->min_width);
}

int					ft_printf_hex_lowercase(t_printf *tab, va_list *args)
{
	char			*str;
	int				h_base;

	h_base = 16;
	if (!(str = hex_handler(tab, args, h_base)))
		return (-1);
	write(1, str, ft_strlen(str));
	ft_free(&str, 1);
	return (tab->min_width);
}

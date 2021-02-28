/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chde-mar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 20:48:48 by chde-mar          #+#    #+#             */
/*   Updated: 2021/02/26 00:12:15 by chde-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				*ft_utoa(unsigned int n)
{
	long int		num;
	int				len;
	char			*str;

	len = 2;
	str = NULL;
	num = n;
	while (num /= 10)
		len++;
	if (!(str = (char *)malloc(sizeof(char) * len)))
		return (NULL);
	str[--len] = '\0';
	while (len--)
	{
		str[len] = n % 10 + '0';
		n = n / 10;
	}
	return (str);
}

int					unsigned_print(int len, t_printf *tab, char *str)
{
	char			*temp;

	len = length_handler(tab, str);
	width_handler(tab, len);
	if (!(temp = ft_malloc(tab->min_width)))
		return (-1);
	if (tab->minus)
		temp = with_minus(temp, len, str, tab);
	else
		temp = without_minus(temp, len, str, tab);
	write(1, temp, ft_strlen(temp));
	ft_free(&temp, 1);
	ft_free(&str, 1);
	return (1);
}

int					ft_printf_unsigned(t_printf *tab, va_list *args)
{
	unsigned int	u;
	int				len;
	char			*temp;
	char			*str;

	u = va_arg(*args, unsigned int);
	if (!(str = ft_utoa(u)))
		return (-1);
	len = ft_strlen(str);
	if ((tab->min_width < 0) && tab->zero)
		tab->zero = 0;
	if (tab->p_dot > len || tab->p_star > len)
	{
		temp = str;
		if (!(str = precision_handler(tab, str, len)))
			return (-1);
		ft_free(&temp, 1);
	}
	if (unsigned_print(len, tab, str) == -1)
		return (-1);
	return (tab->min_width);
}

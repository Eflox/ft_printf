/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chde-mar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 12:56:43 by chde-mar          #+#    #+#             */
/*   Updated: 2021/02/26 00:10:32 by chde-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*add_minus_2(char *str1, t_printf *tab, char *temp)
{
	if (str1[0] != ' ')
	{
		if (!(str1 = ft_strjoin(tab->add_minus, str1)))
			return (NULL);
	}
	tab->min_width += 1;
	ft_free(&temp, 1);
	return (str1);
}

char			*add_minus_1(char *str, int len, t_printf *tab)
{
	char		*str1;
	char		*str2;
	char		*temp;

	if (!(str1 = ft_strdup(str)))
		return (NULL);
	temp = str1;
	if (str1[0] == ' ')
	{
		if (!(str1 = ft_substr(str1, (tab->min_width - len), len)))
			return (NULL);
		free(temp);
		temp = str1;
		if (!(str1 = ft_strjoin(tab->add_minus, str1)))
			return (NULL);
		ft_free(&temp, 1);
		temp = str1;
		if (!(str2 = ft_malloc(tab->min_width - len)))
			return (NULL);
		if (!(str1 = ft_strjoin(str2, str1)))
			return (NULL);
		ft_free(&str2, 1);
	}
	return (add_minus_2(str1, tab, temp));
}

char			*cut_minus(char *str, t_printf *tab, char *new)
{
	char		*str1;
	char		*temp;
	int			i;

	str1 = NULL;
	temp = new;
	if (!(str1 = (char *)malloc(sizeof(char) * ft_strlen(str))))
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		str1[i] = str[i + 1];
		i++;
	}
	str1[i] = '\0';
	tab->check_minus = 1;
	ft_free(&temp, 1);
	return (str1);
}

int				add_remove_minus(t_printf *tab, int len, char *new)
{
	char		*str;
	char		*temp;

	len = length_handler(tab, new);
	width_handler(tab, len);
	if (!(str = ft_malloc(tab->min_width)))
		return (-1);
	if (tab->minus)
		str = with_minus(str, len, new, tab);
	else
		str = without_minus(str, len, new, tab);
	if (tab->check_minus)
	{
		temp = str;
		if (!(str = add_minus_1(str, len, tab)))
			return (-1);
		ft_free(&temp, 1);
	}
	write(1, str, ft_strlen(str));
	ft_free(&str, 1);
	ft_free(&new, 1);
	return (0);
}

int				ft_printf_num(t_printf *tab, va_list *args)
{
	int			str_size;
	char		*str;
	char		*temp;

	if (!(str = ft_itoa(va_arg(*args, int))))
		return (-1);
	str_size = ft_strlen(str);
	if (str[0] == '-' && (tab->minus || tab->zero || tab->p_dot >= str_size
				|| tab->p_star >= str_size))
		if (!(str = cut_minus(str, tab, str)))
			return (-1);
	str_size = ft_strlen(str);
	if ((tab->min_width < 0) && tab->zero)
		tab->zero = 0;
	if ((tab->p_dot > str_size) || (tab->p_star > str_size))
	{
		temp = str;
		if (!(str = precision_handler(tab, str, str_size)))
			return (-1);
		ft_free(&temp, 1);
	}
	if (add_remove_minus(tab, str_size, str) == (-1))
		return (-1);
	return (tab->min_width);
}

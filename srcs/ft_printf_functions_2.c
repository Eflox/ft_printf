/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_functions_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chde-mar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 14:26:28 by chde-mar          #+#    #+#             */
/*   Updated: 2021/02/26 00:07:53 by chde-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*precision_handler(t_printf *tab, char *str, int len)
{
	int			i;
	int			j;
	int			k;
	char		*temp;

	j = 0;
	i = 0;
	k = tab->p_dot;
	if (tab->p_star > (-1))
		k = tab->p_star;
	if (!(temp = ft_malloc(k)))
		return (NULL);
	while (i < (k - len))
	{
		temp[i] = '0';
		i++;
	}
	while (i < k)
	{
		temp[i] = str[j];
		i++;
		j++;
	}
	return (temp);
}

int				ft_free(char **str, int ret)
{
	if (*str)
	{
		free(*str);
		*str = 0;
	}
	return (ret);
}

char			*ft_malloc(int size)
{
	char		*str;
	int			i;

	i = 0;
	str = NULL;
	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (size--)
	{
		str[i] = ' ';
		i++;
	}
	str[i] = '\0';
	return (str);
}

int				write_without_conv(char c)
{
	write(1, &c, 1);
	return (1);
}

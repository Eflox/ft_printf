/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chde-mar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 04:26:05 by chde-mar          #+#    #+#             */
/*   Updated: 2019/12/11 15:08:21 by chde-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void			*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;
	int			i;

	d = dest;
	s = src;
	i = 0;
	if (dest == NULL && src == NULL)
		return (NULL);
	if (dest == NULL)
		return (NULL);
	while (n--)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

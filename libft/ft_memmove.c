/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chde-mar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 06:50:20 by chde-mar          #+#    #+#             */
/*   Updated: 2019/12/11 14:37:00 by chde-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void				*ft_memmove(void *dst, const void *src, size_t len)
{
	char			*d;
	const char		*s;
	char			*lastd;
	const char		*lasts;

	d = dst;
	s = src;
	lastd = d + (len - 1);
	lasts = s + (len - 1);
	if (dst == NULL && src == NULL)
		return (NULL);
	if (d < s)
	{
		while (len--)
			*d++ = *s++;
	}
	else
		while (len--)
			*lastd-- = *lasts--;
	return (dst);
}

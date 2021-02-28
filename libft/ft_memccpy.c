/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chde-mar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 05:57:45 by chde-mar          #+#    #+#             */
/*   Updated: 2019/12/13 07:44:19 by chde-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void				*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	unsigned char	p;
	size_t			i;

	if (dst == NULL && src == NULL)
		return (NULL);
	if (dst == NULL)
		return (NULL);
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	p = (unsigned char)c;
	i = 0;
	while (i < n && (i == 0 || ((i > 0) && s[i - 1] != p)))
	{
		d[i] = s[i];
		i++;
	}
	if (i > 0 && s[i - 1] == p)
		return (d + i);
	else
		return (NULL);
}

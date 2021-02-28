/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chde-mar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 15:16:16 by chde-mar          #+#    #+#             */
/*   Updated: 2019/12/13 07:47:28 by chde-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char			*ft_strtrim(char const *s1, char const *set)
{
	size_t		start;
	size_t		end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start	])
	{
		if (ft_strchr(set, s1[start]) == NULL)
			break ;
		start++;
	}
	end = ft_strlen(s1) - 1;
	while (end > 0)
	{
		if (ft_strchr(set, s1[end]) == NULL)
			break ;
		end--;
	}
	if (start > end || ft_strlen(s1) == 0)
		return (ft_substr(s1, 0, 0));
	return (ft_substr(s1, start, (end - start + 1)));
}

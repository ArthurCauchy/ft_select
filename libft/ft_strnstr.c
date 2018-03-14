/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 17:48:05 by acauchy           #+#    #+#             */
/*   Updated: 2017/11/22 10:12:37 by acauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	needle_len;

	if (ft_strlen(needle) == 0)
		return ((char*)haystack);
	i = 0;
	j = 0;
	needle_len = ft_strlen(needle);
	while (i < len && i < ft_strlen(haystack))
	{
		while (j < needle_len && i + j < len)
		{
			if (haystack[i + j] != needle[j])
				break ;
			if (j == needle_len - 1)
				return ((char*)haystack + i);
			++j;
		}
		j = 0;
		++i;
	}
	return (0);
}

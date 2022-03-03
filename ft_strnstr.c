/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetchda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 13:18:59 by porrapat          #+#    #+#             */
/*   Updated: 2022/02/07 13:22:55 by porrapat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	nh;
	size_t	nn;
	size_t	nh_temp;

	nh = 0;
	nn = 0;
	if (needle[0] == '\0')
		return ((char *) haystack);
	while (nh < len && haystack[nh] != '\0')
	{
		if (haystack[nh] == needle[nn])
		{
			nh_temp = nh;
			while (haystack[nh++] == needle[nn++])
			if (needle[nn] == '\0')
				return ((char *)haystack + nh_temp);
			else
			{
				nh -= nh_temp;
				nn = 0;
			}	
		}
		nh++;
	}
	return (NULL);
}
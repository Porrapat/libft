/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetchda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 13:18:59 by porrapat          #+#    #+#             */
/*   Updated: 2022/02/07 13:22:55 by porrapat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// dst = "abcd"
// src = "efgh"
// max_len = ? 4 = ft_strlen(src)
// dst = efgh

// max_len = 3
// dst = efgd

// max_len = 2
// dst = efcd

// max_len = 0
// dst = abcd // not change


// Example 2
// dst = "abcd"
// src = "efghijkl"
// maxlen = 8

// dst = "efgh" 1? - Right
// dst = "efghijkl" 2?  - Wrong

// Example 3
// dst = "abcd"
// src = "efghijkl"
// maxlen = 100000

// dst = "efgh" 

#include <stdio.h>
size_t	ft_strlcpy(char *dst, const char *src, size_t maxlen)
{
	size_t	srclen;

	srclen = ft_strlen(src);
	if (srclen + 1 < maxlen)
	{
		ft_memcpy(dst, src, srclen + 1);
	}
	else if (maxlen != 0)
	{
		ft_memcpy(dst, src, maxlen - 1);
		dst[maxlen - 1] = '\0';
	}
	return (srclen);
}

int main()
{
	char dst[] = "abcdxxxx";		// Writable -- Stack Memory
	// char *dst = "abcd";			// Un-Write -- bss Memory -- read-only
	char src[] = "efghijklmn";

	ft_strlcpy(dst, src, 12);
	// dst[4] = '\0';

	printf("%s\n", dst);
	return (0);
}

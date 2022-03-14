/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetchda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 13:18:59 by porrapat          #+#    #+#             */
/*   Updated: 2022/02/07 13:22:55 by porrapat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	lenr;
	size_t	i;

	if (!s)
		return (NULL);
	lenr = len;
	if (ft_strlen(s) <= start || (int)len < 0)
		lenr = 0;
	else if (len >= ft_strlen(s))
		lenr = ft_strlen(s) - start;
	ptr = (char *)malloc(lenr + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	while (s[start] && i < lenr)
		ptr[i++] = s[start++];
	ptr[i] = '\0';
	return (ptr);
}

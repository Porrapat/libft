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
	char	*result;
	size_t	result_size;
	size_t	s_len;

	if (!s)
	{
		return (NULL);
	}
	s_len = ft_strlen(s);
	result_size = 0;
	if (start < s_len)
	{
		result_size = s_len - start;
	}
	if (result_size > len)
	{
		result_size = len;
	}
	result = (char *)malloc(result_size + 1);
	if (!result)
	{
		return (NULL);
	}
	ft_strlcpy(result, s + start, result_size + 1);
	return (result);
}

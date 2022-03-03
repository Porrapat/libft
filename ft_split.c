/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetchda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 13:18:59 by porrapat          #+#    #+#             */
/*   Updated: 2022/02/07 13:22:55 by porrapat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count(char const *s, char c)
{
	int	i;
	int	n;

	n = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c && s[i - 1] != c)
			n++;
		i++;
	}
	if (!s[i] && s[i - 1] != c)
		n++;
	return (n);
}

int	endstr(char const *s, char c, int start)
{
	int	end;

	end = start;
	while (s[end] && s[end] != c)
		end++;
	return (end);
}

char	*copy(char const *s, int start, int end)
{
	char	*cpy;
	int		i;

	i = 0;
	cpy = malloc(sizeof(char) * (end - start));
	if (!cpy)
		return (0);
	while (start < end)
	{
		cpy[i] = s[start];
		i++;
		start++;
	}
	cpy[i] = '\0';
	return (cpy);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		num;
	int		j;
	int		i;

	num = count(s, c);
	split = (char **)malloc(sizeof(char *) * (num + 1));
	if (!split)
		return (0);
	j = 0;
	i = 0;
	while (j < num)
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		split[j] = copy(s, i, endstr(s, c, i));
		j++;
		i = endstr(s, c, i);
	}
	split[j] = 0;
	return (split);
}

#include <stdio.h>

static int	count_me(const char *str, char sep)
{
	int	words;

	words = 0;
	while (*str)
	{
		while (*str && *str == sep)
			str++;
		if (*str && *str != sep)
			words++;
		while (*str && *str != sep)
			str++;
	}
	return (words);
}

static int	count_you(char const *s, char c)
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

int main()
{
    printf("count me is %d | count you is %d\n", count_me("          ", ' '), count_you("          ", ' '));
    printf("count me is %d | count you is %d\n", count_me("abc,123", ','), count_you("abc,123", ','));
}
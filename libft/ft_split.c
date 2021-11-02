#include <stdlib.h>
#include "libft.h"

static	size_t	split_string_count(char const *s, char c)
{
	size_t	count;

	if (!s || !*s)
		return (0);
	count = 0;
	while (*s)
	{
		if (*s == c)
		{
			while (*s && *s == c)
				s++;
			if (*s)
				count++;
			else
				break ;
		}
		s++;
	}
	return (count + 1);
}

static void	ft_free(char **new_string, size_t count)
{
	while (count > 0)
		free(new_string[--count]);
	free(new_string);
}

static	size_t	word_len(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (*s++)
	{
		len++;
		if (*s == c)
			return (len);
	}
	return (len);
}

static char	**str_cr(char const *s, char c, size_t count_str, size_t i)
{
	char	**new_string;
	size_t	string_len;

	new_string = (char **)malloc(sizeof(char *) * (count_str + 1));
	if (NULL == new_string)
		return (NULL);
	while (i < count_str)
	{
		string_len = word_len(s, c);
		new_string[i] = (char *)malloc(sizeof(char) * (string_len + 1));
		if (NULL == new_string[i])
		{
			ft_free(new_string, i);
			return (NULL);
		}
		new_string[i] = ft_memcpy(new_string[i], s, string_len);
		new_string[i++][string_len] = '\0';
		while (*s && *s != c)
			s++;
		while (*s && *s == c)
			s++;
	}
	new_string[i] = NULL;
	return (new_string);
}

char	**ft_split(char const *s, char c)
{
	size_t	count_str;
	char	**new_string;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	while (*s && *s == c)
		s++;
	count_str = split_string_count(s, c);
	new_string = str_cr(s, c, count_str, i);
	return (new_string);
}

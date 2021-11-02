#include "get_next_line.h"

int	find_symbol(char *cache)
{
	int	i;
	int	position;

	if (!cache)
		return (-1);
	i = 0;
	position = -1;
	while (cache[i] && cache[i] != '\n')
		i++;
	if (cache[i] == '\n')
		position = i;
	return (position);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (*str++)
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	unsigned int	s1_len;
	unsigned int	s2_len;
	char			*new_str;
	int				sum_len;

	if (!s1)
		s1_len = 0;
	else
		s1_len = ft_strlen(s1);
	if (!s2)
		s2_len = 0;
	else
		s2_len = ft_strlen(s2);
	sum_len = s1_len + s2_len;
	new_str = (char *)malloc(sizeof(char) * (sum_len + 1));
	if (NULL == new_str)
		return (NULL);
	while (s1_len--)
		new_str[s1_len] = s1[s1_len];
	free(s1);
	new_str[sum_len] = '\0';
	while (s2_len--)
		new_str[sum_len-- - 1] = s2[s2_len];
	return (new_str);
}

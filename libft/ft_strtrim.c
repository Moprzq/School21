#include <stdlib.h>
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	start;
	unsigned int	end;
	unsigned int	set_len;
	char			*new_str;

	if (!s1)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	if (end == 0)
		return (ft_substr(s1, 0, 0));
	set_len = ft_strlen(set);
	while (start < end && ft_memchr(set, s1[start], set_len))
		start++;
	while (end - 1 > start && ft_memchr(set, s1[end - 1], set_len))
		end--;
	new_str = ft_substr(s1, start, end - start);
	return (new_str);
}

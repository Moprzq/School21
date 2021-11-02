#include <stdlib.h>

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	si;
	size_t	ti;

	si = 0;
	if (!(*to_find))
		return ((char *) str);
	while (str[si] && si < len)
	{
		ti = 0;
		if (str[si] == to_find[ti])
		{
			while (str[si + ti] == to_find[ti] && (si + ti < len))
			{
				if (to_find[ti + 1] == '\0')
					return ((char *)(str + si));
				ti++;
			}
		}
		si++;
	}
	return (NULL);
}

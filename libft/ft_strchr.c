#include <stdlib.h>

char	*ft_strchr(const char *s, int c)
{
	while ((unsigned char) *s)
	{
		if ((unsigned char) *s == (unsigned char) c)
			return ((char *) s);
		s++;
	}
	if ((unsigned char) *s == (unsigned char) c)
		return ((char *) s);
	return (NULL);
}

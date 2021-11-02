#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*new_s;
	size_t	len;

	len = ft_strlen(s) + 1;
	new_s = (char *)malloc(len * sizeof(char));
	if (NULL == new_s)
		return (NULL);
	ft_memcpy(new_s, s, len);
	return (new_s);
}

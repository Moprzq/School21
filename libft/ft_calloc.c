#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*str;
	int	n;

	str = (void *)malloc(size * nmemb);
	if (NULL == str)
		return (NULL);
	n = size * nmemb;
	while (n-- > 0)
		*str++ = '\0';
	return (str);
}

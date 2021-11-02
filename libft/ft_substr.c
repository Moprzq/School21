#include <stdlib.h>
#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	unsigned int	s_len;
	char			*substr;
	unsigned int	sub_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (s_len < start)
		return (ft_strdup(""));
	if (s_len - start >= len)
		sub_len = len;
	else
		sub_len = s_len - start;
	substr = (char *)malloc(sizeof(char) * (sub_len + 1));
	if (NULL == substr)
		return (NULL);
	ft_strlcpy(substr, s + start, sub_len + 1);
	return (substr);
}

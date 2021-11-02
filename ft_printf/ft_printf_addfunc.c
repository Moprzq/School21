#include "ft_printf_header.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}

char	digit_to_char(int digit, int uppercase)
{
	if (digit < 10)
		return ((char)(digit + 48));
	else if (uppercase == 2)
		return ((char)(digit + 55));
	else
		return ((char)(digit + 87));
}

char	*ft_arr_cr(unsigned long n, int rank, int base, int uppercase)
{
	char			*nbr;
	unsigned long	div;

	nbr = (char *)malloc(sizeof(char) * (rank + 1));
	if (!nbr)
		return (NULL);
	div = 1;
	while (--rank)
		div = div * base;
	while (div != 0)
	{
		nbr[rank++] = digit_to_char(n / div, uppercase);
		n = n % div;
		div = div / base;
	}
	nbr[rank] = '\0';
	return (nbr);
}

char	*ft_itoa(unsigned long n, int base, int uppercase)
{
	int				rank;
	unsigned long	div;
	char			*nbr;

	rank = 1;
	div = n;
	while (div / base)
	{
		rank++;
		div = div / base;
	}
	nbr = ft_arr_cr(n, rank, base, uppercase);
	return (nbr);
}

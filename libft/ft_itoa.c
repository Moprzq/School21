#include <stdlib.h>

char	*ft_arr_cr(int rank, int div, int sign, unsigned int module_n)
{
	char	*nbr;

	nbr = (char *)malloc(sizeof(char) * (rank + sign + 1));
	if (NULL == nbr)
		return (NULL);
	div = 1;
	while (--rank != 0)
		div = div * 10;
	if (sign == 1)
		nbr[rank] = '-';
	while (div != 0)
	{
		nbr[sign + rank++] = (module_n / div) + 48;
		module_n = module_n % div;
		div = div / 10;
	}
	nbr[sign + rank] = '\0';
	return (nbr);
}

char	*ft_itoa(int n)
{
	int				rank;
	int				div;
	int				sign;
	char			*nbr;
	unsigned int	module_n;

	rank = 1;
	div = n;
	sign = 0;
	module_n = n;
	if (n < 0)
	{
		sign = 1;
		module_n = n * -1;
	}
	while (div / 10)
	{
		rank++;
		div = div / 10;
	}
	nbr = ft_arr_cr(rank, div, sign, module_n);
	return (nbr);
}

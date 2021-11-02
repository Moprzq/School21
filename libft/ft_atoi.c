#include <stdio.h>

static	int	ft_isspace(int c)
{
	if (c == 32 || (9 <= c && c <= 13))
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int				i;
	unsigned long	res;
	int				sign;

	i = 0;
	res = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign = -1;
	}
	while ('0' <= str[i] && str[i] <= '9')
	{
		if (res >= 9223372036854775807)
		{
			if (sign == 1)
				return (-1);
			return (0);
		}
		res = res * 10 + (str[i++] - 48);
	}
	return (res * sign);
}

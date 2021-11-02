#include "ft_printf_header.h"

void	proc_c(t_params *params, int c)
{
	params->out += write(1, &c, 1);
}

void	proc_s(t_params *params)
{
	char	*str;
	size_t	len;

	str = va_arg(params->args, char *);
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	params->out += write(1, str, len);
}

void	proc_num(t_params *params, unsigned long nb, int base, int uppercase)
{
	char	*str;

	str = ft_itoa(nb, base, uppercase);
	if (uppercase == 3)
		params->out += write(1, "0x", 2);
	params->out += write(1, str, ft_strlen(str));
	free(str);
}

void	proc_signed(t_params *params)
{
	long	nb;

	nb = va_arg(params->args, int);
	if (nb >= 0)
		proc_num(params, nb, 10, 0);
	else
	{
		params->out += write(1, "-", 1);
		proc_num(params, nb * -1, 10, 0);
	}
}

void	proc_unsigned(t_params *params, int uppercase)
{
	if (uppercase == 0)
		proc_num(params, va_arg(params->args, unsigned int), 10, 0);
	if (uppercase == 1)
		proc_num(params, va_arg(params->args, unsigned int), 16, 1);
	if (uppercase == 2)
		proc_num(params, va_arg(params->args, unsigned int), 16, 2);
	if (uppercase == 3)
		proc_num(params, va_arg(params->args, unsigned long), 16, 3);
}

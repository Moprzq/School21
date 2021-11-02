#include "ft_printf_header.h"

void	proc_type(t_params *params)
{
	if (params->main_arg[0] == 'c')
		proc_c(params, va_arg(params->args, int));
	else if (params->main_arg[0] == 's')
		proc_s(params);
	else if (params->main_arg[0] == 'd' || params->main_arg[0] == 'i')
		proc_signed(params);
	else if (params->main_arg[0] == 'u')
		proc_unsigned(params, 0);
	else if (params->main_arg[0] == 'x')
		proc_unsigned(params, 1);
	else if (params->main_arg[0] == 'X')
		proc_unsigned(params, 2);
	else if (params->main_arg[0] == 'p')
		proc_unsigned(params, 3);
	else if (params->main_arg[0] == '%')
		proc_c(params, '%');
	else if (params->main_arg[0] == '\0')
		params->main_arg--;
	else
		params->out += write(1, params->main_arg, 1);
}

void	parameter_proc(t_params *params)
{
	while (params->main_arg[0] != '\0')
	{
		if (params->main_arg[0] == '%')
		{
			params->main_arg++;
			proc_type(params);
			params->main_arg++;
			continue ;
		}
		params->out += write(1, params->main_arg, 1);
		params->main_arg++;
	}
}

int	ft_printf(const char *main_arg, ...)
{
	t_params	*params;
	int			out;

	out = 0;
	params = malloc(sizeof(t_params));
	if (!params)
		return (out);
	params->main_arg = (char *)main_arg;
	params->out = 0;
	va_start(params->args, main_arg);
	parameter_proc(params);
	va_end(params->args);
	out = params->out;
	free(params);
	return (out);
}

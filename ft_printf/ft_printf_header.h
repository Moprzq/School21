#ifndef FT_PRINTF_HEADER_H
# define FT_PRINTF_HEADER_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_params
{
	char		*main_arg;
	va_list		args;
	int			out;
}				t_params;
int		ft_printf(const char *main_arg, ...);
void	proc_c(t_params *params, int c);
void	proc_s(t_params *params);
void	proc_num(t_params *params, unsigned long nb, int base, int uppercase);
void	proc_signed(t_params *params);
void	proc_unsigned(t_params *params, int uppercase);
char	*ft_itoa(unsigned long n, int base, int uppercase);
char	*ft_arr_cr(unsigned long n, int rank, int base, int uppercase);
char	digit_to_char(int digit, int uppercase);
size_t	ft_strlen(const char *str);
#endif
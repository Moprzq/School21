#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	char	div;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = n * -1;
	}
	if (n >= 10)
		ft_putnbr_fd(n / 10, fd);
	div = n % 10 + 48;
	write(fd, &div, 1);
}

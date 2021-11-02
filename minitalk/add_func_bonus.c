/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_func_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharman <kcharman@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 17:27:00 by kcharman          #+#    #+#             */
/*   Updated: 2021/10/20 17:31:10 by kcharman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void	ft_write_str(char *str)
{
	if (!str)
		return ;
	write(1, str, ft_strlen(str));
}

void	ft_send_signal(pid_t pid, int signum)
{
	usleep(75);
	usleep(75);
	if (kill(pid, signum) == -1)
		ft_write_str("Error in sending signals!\n");
	usleep(75);
	usleep(75);
}

void	*ft_calloc(int len, int size)
{
	char	*str;
	int		i;

	str = (char *)malloc(len * size);
	if (!str)
		return (NULL);
	i = 0;
	while (i != len * size)
		str[i++] = '\0';
	return (str);
}

void	ft_putnbr(int n)
{
	char	divdigit;

	if (n >= 10)
	{
		divdigit = (n % 10) + 48;
		n = n / 10;
		ft_putnbr(n);
		write(1, &divdigit, 1);
	}
	else if (n >= 0 && n <= 9)
	{
		divdigit = n + 48;
		write(1, &divdigit, 1);
	}
}

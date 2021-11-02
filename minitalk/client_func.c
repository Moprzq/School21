/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharman <kcharman@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 15:05:53 by kcharman          #+#    #+#             */
/*   Updated: 2021/10/20 18:23:43 by kcharman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_send_len(pid_t server_pid, int len)
{
	static int		my_len;
	static int		counter;
	static pid_t	my_pid;

	if (!my_len)
	{
		my_len = len;
		counter = 1 << 30;
		my_pid = server_pid;
	}
	if (counter)
	{
		if (counter & my_len)
			ft_send_signal(my_pid, SIGUSR1);
		else
			ft_send_signal(my_pid, SIGUSR2);
		counter >>= 1;
	}
}

int	ft_validate_pid(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		i++;
	}
	return (1);
}

int	ft_valid_arg(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_write_str("Check arguments!\nUsage ./client PID message\n");
		return (-1);
	}
	if (ft_strlen(argv[2]) == 0)
	{
		ft_write_str("Check your string!\n");
		return (-1);
	}
	if (ft_validate_pid(argv[1]) == -1)
	{
		ft_write_str("Invalid PID\n");
		return (-1);
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	size_t	i;
	ssize_t	res;
	int		digits;

	digits = 0;
	i = 0;
	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + ((char)str[i] - '0');
		i++;
		digits++;
	}
	return ((int)res);
}

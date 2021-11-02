/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharman <kcharman@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 15:05:50 by kcharman          #+#    #+#             */
/*   Updated: 2021/10/20 17:23:57 by kcharman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_get_len(int signum, pid_t client_pid, int *len)
{
	static int		counter;

	if (!counter)
		counter = 1 << 30;
	if (signum == SIGUSR1)
		*len = *len | counter;
	counter >>= 1;
	ft_send_signal(client_pid, SIGUSR1);
}

int	ft_if_not_str(int *index, char **str, pid_t client_pid, int len)
{
	*index = 0;
	*str = ft_calloc(len, sizeof(**str));
	if (!*str)
	{
		ft_send_signal(client_pid, SIGUSR2);
		return (-1);
	}
	return (1);
}

void	ft_write_and_free(char **str)
{
	int	i;

	i = ft_strlen(*str);
	write(1, *str, i);
	free(*str);
	*str = NULL;
	ft_write_str("\nPID is: ");
	ft_putnbr(getpid());
	write(1, "\n", 1);
}

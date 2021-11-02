/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_addfunc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharman <kcharman@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 14:53:13 by kcharman          #+#    #+#             */
/*   Updated: 2021/10/15 20:53:37 by kcharman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (1);
	else
		return (0);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char) s1[i] - (unsigned char) s2[i]);
		i++;
	}
	if (s1[i] != s2[i])
		return ((unsigned char) s1[i] - (unsigned char) s2[i]);
	return (0);
}

long	ft_atoi(const char *str)
{
	int				i;
	unsigned long	res;
	int				sign;

	i = 0;
	res = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign = -1;
	}
	while ('0' <= str[i] && str[i] <= '9')
		res = res * 10 + (str[i++] - 48);
	return (res * sign);
}

void	arg_error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

void	fill_elem(t_stack *elem, int value)
{
	elem->value = value;
	elem->score = 0;
	elem->oper_a = 0;
	elem->oper_b = 0;
}

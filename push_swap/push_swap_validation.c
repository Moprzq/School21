/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_validation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharman <kcharman@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 15:53:09 by kcharman          #+#    #+#             */
/*   Updated: 2021/10/15 20:54:07 by kcharman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	arg_validation(char **argv)
{
	int	res;
	int	i;
	int	j;

	res = 1;
	i = 1;
	while (res == 1 && argv[i])
	{
		j = 0;
		while (res == 1 && argv[i][j])
		{
			if (argv[i][j] == '-' || argv[i][j] == '+')
				j++;
			if (ft_isdigit(argv[i][j]) == 0)
				arg_error();
			j++;
		}
		i++;
	}
	return (res);
}

int	duplicate_validation(char **argv)
{
	int	res;
	int	i;
	int	j;

	res = 1;
	i = 1;
	while (res == 1 && argv[i + 1])
	{
		j = i + 1;
		while (res == 1 && argv[j])
		{
			if (ft_strcmp(argv[i], argv[j++]) == 0)
				arg_error();
		}
		i++;
	}
	return (res);
}

int	*integer_validation(char **argv, int i)
{
	long	*arr;
	int		*int_arr;

	arr = (long *)malloc(i * sizeof(long));
	if (arr == NULL)
		return (NULL);
	if (!args_is_int(argv, arr))
	{
		free(arr);
		arg_error();
	}
	int_arr = array_to_int(arr, i);
	return (int_arr);
}

int	args_is_int(char **argv, long *arr)
{
	int			i;
	int			res;

	i = 1;
	res = 1;
	while (argv[i])
	{
		arr[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	i = i - 2;
	while (i >= 0 && res == 1)
	{
		if (arr[i] > INT_MAX || arr[i] < INT_MIN)
			res = 0;
		i--;
	}
	return (res);
}

int	*array_to_int(long *arr, int i)
{
	int	k;
	int	*int_arr;

	k = 0;
	int_arr = malloc(i * sizeof(int));
	if (int_arr == NULL)
		return (NULL);
	while (k < i)
	{
		int_arr[k] = (int) arr[k];
		k++;
	}
	free(arr);
	return (int_arr);
}

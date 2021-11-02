/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_create_stack.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharman <kcharman@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:02:42 by kcharman          #+#    #+#             */
/*   Updated: 2021/10/16 13:21:25 by kcharman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_stack(int *arr, int count, t_inf *inf)
{
	int		i;
	t_stack	*elem;
	t_stack	*head;

	i = 0;
	elem = (t_stack *)malloc(sizeof(t_stack));
	if (!elem)
		ft_free_and_exit(inf, NULL, arr);
	head = elem;
	while (i < count)
	{
		fill_elem(elem, arr[i]);
		if (i++ < count - 1)
		{
			elem->next = (t_stack *)malloc(sizeof(t_stack));
			if (!elem->next)
				ft_free_and_exit(inf, head, arr);
		}
		else
			elem->next = NULL;
		elem = elem->next;
	}
	elem = head;
	return (elem);
}

void	fill_inf(t_inf *inf, t_stack *a, int count, int *arr)
{
	inf->a = a;
	inf->b = NULL;
	inf->count = count;
	inf->count_a = count;
	inf->count_b = 0;
	inf->max = find_max(arr, count);
	inf->min = find_min(arr, count);
	inf->mid = find_middle(arr, count);
}

int	is_not_sorted(t_stack *a)
{
	if (!a)
		return (0);
	while (a && (a->next))
	{
		if (a->value > a->next->value)
			return (1);
		a = a->next;
	}
	return (0);
}

int	find_max(int *arr, int count)
{
	int	max;
	int	i;

	i = 0;
	max = arr[0];
	while (i < count)
	{
		if (max < arr[i])
			max = arr[i];
		i++;
	}
	return (max);
}

int	find_min(int *arr, int count)
{
	int	min;
	int	i;

	i = 0;
	min = arr[0];
	while (i < count)
	{
		if (min > arr[i])
			min = arr[i];
		i++;
	}
	return (min);
}

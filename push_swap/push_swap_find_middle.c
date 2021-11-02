/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_find_middle.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharman <kcharman@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 16:55:53 by kcharman          #+#    #+#             */
/*   Updated: 2021/10/15 20:53:41 by kcharman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_middle(int *arr, int size)
{
	int	count1;
	int	count2;
	int	mid;

	count1 = 0;
	while (count1++ < size - 2)
	{
		count2 = 0;
		while (count2 < size - 1)
		{
			if (arr[count2] > arr[count2 + 1])
				ft_swap(&arr[count2], &arr[count2 + 1]);
			count2++;
		}
	}
	count1 = 0;
	mid = arr[size / 2];
	return (mid);
}

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

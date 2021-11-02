/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharman <kcharman@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 14:53:30 by kcharman          #+#    #+#             */
/*   Updated: 2021/10/16 13:27:39 by kcharman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_and_exit(t_inf *inf, t_stack *stack, int *arr)
{
	if (stack)
		free_stack(stack);
	if (inf)
	{
		free_stack(inf->a);
		free_stack(inf->b);
		free(inf);
	}
	if (arr)
		free(arr);
	exit(1);
}

void	free_stack(t_stack *stack)
{
	t_stack	*temp;

	if (!stack)
		return ;
	while (stack)
	{
		temp = stack;
		stack = temp->next;
		free(temp);
	}
}

void	ft_free(t_inf *inf, int *arr)
{
	if (inf)
	{
		free_stack(inf->a);
		free_stack(inf->b);
		free(inf);
	}
	if (arr)
		free(arr);
}

int	main(int argc, char **argv)
{
	t_inf	*inf;
	int		*arr;

	if (argc < 2)
		exit(1);
	if (arg_validation(argv) && duplicate_validation(argv))
	{
		arr = integer_validation(argv, argc - 1);
		if (arr)
		{	
			inf = (t_inf *)malloc(sizeof(t_inf));
			if (!inf)
				ft_free_and_exit(NULL, NULL, arr);
			fill_inf(inf, create_stack(arr, argc - 1, inf), argc - 1, arr);
		}
		if (is_not_sorted(inf->a))
			start_sort(inf);
		ft_free(inf, arr);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharman <kcharman@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 18:47:28 by kcharman          #+#    #+#             */
/*   Updated: 2021/10/15 20:54:00 by kcharman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	start_sort(t_inf *inf)
{
	if (inf->count <= 3)
		sort_3_elem(inf);
	else if (inf->count <= 5)
		sort_5_elem(inf);
	else
		sort_elems(inf);
}

void	sort_3_elem(t_inf *inf)
{
	int	max_a;

	max_a = find_max_list(inf->a);
	if (inf->count_a == 1)
		return ;
	else if (inf->count_a == 2)
	{
		if (inf->a->value > inf->a->next->value)
			sa(inf->a, 1);
		return ;
	}
	else
	{
		if (inf->a->value == max_a)
			ra(&inf->a, 1);
		if (inf->a->next->value == max_a)
			rra(&inf->a, 1);
		if (inf->a->value > inf->a->next->value)
			sa(inf->a, 1);
	}
}

void	sort_5_elem(t_inf *inf)
{
	while (inf->count_b < 2)
	{
		if (inf->a->value == inf->min || inf->a->value == inf->max)
			pb(inf);
		else if (inf->a->next->value == inf->min
			|| inf->a->next->value == inf->max)
			ra(&inf->a, 1);
		else
			rra(&inf->a, 1);
	}
	sort_3_elem(inf);
	pa(inf);
	pa(inf);
	if (inf->a->value == inf->max)
		ra(&inf->a, 1);
	else
	{
		sa(inf->a, 1);
		ra(&inf->a, 1);
	}
}

int	find_max_list(t_stack *stack)
{
	int	max;

	max = stack->value;
	if (!stack)
		return (0);
	while (stack)
	{
		if (max < stack->value)
			max = stack->value;
		stack = stack->next;
	}
	return (max);
}

void	sort_elems(t_inf *inf)
{
	t_stack	*min_score;

	while (inf->count_a > 2)
	{
		if (inf->a->value != inf->min && inf->a->value != inf->max)
		{
			pb(inf);
			if (inf->b->value > inf->mid && inf->b->next)
				rb(&inf->b, 1);
		}
		else
			ra(&inf->a, 1);
	}
	if (inf->a->value < inf->a->next->value)
		sa(inf->a, 1);
	pa(inf);
	while (inf->count_b != 0)
	{
		find_score(inf);
		min_score = find_min_score(inf->b);
		do_rotate(inf, min_score);
		pa(inf);
	}
	last_rotate(inf);
}

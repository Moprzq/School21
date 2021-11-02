/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharman <kcharman@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 20:55:10 by kcharman          #+#    #+#             */
/*   Updated: 2021/10/16 08:36:11 by kcharman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_score(t_inf *inf)
{
	t_stack	*temp;

	temp = inf->b;
	find_operations_a(inf);
	find_operations_b(inf);
	while (temp)
	{
		if (temp->oper_a <= 0 && temp->oper_b <= 0)
		{
			if (temp->oper_a < temp->oper_b)
				temp->score = temp->oper_a * -1;
			else
				temp->score = temp->oper_b * -1;
		}
		else if (temp->oper_a < 0 && temp->oper_b > 0)
			temp->score = (temp->oper_a * -1) + temp->oper_b;
		else if (temp->oper_a > 0 && temp->oper_b < 0)
			temp->score = (temp->oper_b * -1) + temp->oper_a;
		else
			find_score_part2(temp);
		temp = temp->next;
	}
}

void	find_score_part2(t_stack *temp)
{
	if (temp->oper_a < temp->oper_b)
		temp->score = temp->oper_b;
	else
		temp->score = temp->oper_a;
}

void	find_operations_b(t_inf *inf)
{
	int		i;
	int		half;
	t_stack	*temp;

	i = 0;
	half = inf->count_b / 2;
	temp = inf->b;
	while (i <= half)
	{
		temp->oper_b = i++;
		temp = temp->next;
	}
	if (inf->count_b % 2 == 0)
		i--;
	while (--i >= 1)
	{
		temp->oper_b = -1 * i;
		temp = temp->next;
	}
}

void	find_operations_a(t_inf *inf)
{
	int		half;
	int		i;
	t_stack	*t_b;
	t_stack	*t_a;

	half = inf->count_a / 2;
	t_b = inf->b;
	while (t_b)
	{
		t_a = inf->a;
		i = 1;
		t_b->oper_a = 0;
		while (i <= half)
		{
			if (t_a->value < t_b->value && t_b->value < t_a->next->value)
				t_b->oper_a = i;
			t_a = t_a->next;
			i++;
		}
		if (inf->count_a % 2 == 0)
			i--;
		find_operations_a_part2(t_a, t_b, i);
		t_b = t_b->next;
	}
}

void	find_operations_a_part2(t_stack *t_a, t_stack *t_b, int i)
{
	while (--i >= 1)
	{
		if (t_a->value < t_b->value && t_b->value < t_a->next->value)
			t_b->oper_a = -1 * i;
		t_a = t_a->next;
	}
}

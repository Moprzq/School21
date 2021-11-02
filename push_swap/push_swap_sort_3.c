/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharman <kcharman@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 21:15:25 by kcharman          #+#    #+#             */
/*   Updated: 2021/10/15 20:53:55 by kcharman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_rotate(t_inf *inf, t_stack *min)
{
	while (min->oper_a != 0 || min->oper_b != 0)
	{
		if (min->oper_a > 0 && min->oper_b > 0)
		{
			rr(inf);
			min->oper_a -= 1;
			min->oper_b -= 1;
		}
		else if (min->oper_a < 0 && min->oper_b < 0)
		{
			rrr(inf);
			min->oper_a += 1;
			min->oper_b += 1;
		}
		else
			do_rotate_part2(inf, min);
	}
}

void	do_rotate_part2(t_inf *inf, t_stack *min)
{
	if (min->oper_a < 0)
	{
		rra(&inf->a, 1);
		min->oper_a += 1;
	}
	if (min->oper_a > 0)
	{
		ra(&inf->a, 1);
		min->oper_a -= 1;
	}
	if (min->oper_b < 0)
	{
		rrb(&inf->b, 1);
		min->oper_b += 1;
	}
	if (min->oper_b > 0)
	{
		rb(&inf->b, 1);
		min->oper_b -= 1;
	}
}

void	last_rotate(t_inf *inf)
{
	int		up;
	t_stack	*temp_a;
	int		rotates;

	up = 0;
	temp_a = inf->a;
	while (temp_a->value != inf->min)
	{
		temp_a = temp_a->next;
		up++;
	}
	if (up < inf->count / 2)
		rotates = up;
	else
		rotates = up - inf->count;
	last_rotate_part2(inf, rotates);
}

void	last_rotate_part2(t_inf *inf, int rotates)
{
	while (rotates != 0)
	{
		if (rotates > 0)
		{
			ra(&inf->a, 1);
			rotates--;
		}
		else
		{
			rra(&inf->a, 1);
			rotates++;
		}
	}
}

t_stack	*find_min_score(t_stack *b)
{
	t_stack	*min_score;

	min_score = b;
	while (b)
	{
		if (min_score->score > b->score)
			min_score = b;
		b = b->next;
	}
	return (min_score);
}

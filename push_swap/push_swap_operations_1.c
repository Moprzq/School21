/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations_1.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharman <kcharman@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 19:47:30 by kcharman          #+#    #+#             */
/*   Updated: 2021/10/15 20:53:42 by kcharman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a, int i)
{
	int	temp;

	if (!a || !(a->next))
		return ;
	temp = a->value;
	a->value = a->next->value;
	a->next->value = temp;
	if (i == 1)
		write(1, "sa\n", 3);
}

void	sb(t_stack *b, int i)
{
	int	temp;

	if (!b || !(b->next))
		return ;
	temp = b->value;
	b->value = b->next->value;
	b->next->value = temp;
	if (i == 1)
		write(1, "sb\n", 3);
}

void	ss(t_inf *inf)
{
	sa(inf->a, 0);
	sb(inf->b, 0);
	write(1, "ss\n", 3);
}

void	pa(t_inf *inf)
{
	t_stack	*temp;

	if (inf->b == NULL)
		return ;
	temp = inf->b;
	inf->b = inf->b->next;
	temp->next = inf->a;
	inf->a = temp;
	inf->count_a += 1;
	inf->count_b -= 1;
	write(1, "pa\n", 3);
}

void	pb(t_inf *inf)
{
	t_stack	*temp;

	if (inf->a == NULL)
		return ;
	temp = inf->a;
	inf->a = inf->a->next;
	temp->next = inf->b;
	inf->b = temp;
	inf->count_b += 1;
	inf->count_a -= 1;
	write(1, "pb\n", 3);
}

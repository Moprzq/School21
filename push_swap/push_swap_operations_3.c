/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations_3.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharman <kcharman@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:36:12 by kcharman          #+#    #+#             */
/*   Updated: 2021/10/15 20:53:49 by kcharman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **a, int i)
{
	t_stack	*head;
	t_stack	*tail;
	t_stack	*replace;

	if (!(*a) || !(*a)->next)
		return ;
	head = *a;
	tail = *a;
	while (tail->next->next != NULL)
		tail = tail->next;
	replace = tail->next;
	tail->next = NULL;
	replace->next = head;
	*a = replace;
	if (i == 1)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **b, int i)
{
	t_stack	*head;
	t_stack	*tail;
	t_stack	*replace;

	if (!(*b) || !(*b)->next)
		return ;
	head = *b;
	tail = *b;
	while (tail->next->next != NULL)
		tail = tail->next;
	replace = tail->next;
	tail->next = NULL;
	replace->next = head;
	*b = replace;
	if (i == 1)
		write(1, "rrb\n", 4);
}

void	rrr(t_inf *inf)
{
	rra(&inf->a, 0);
	rrb(&inf->b, 0);
	write(1, "rrr\n", 4);
}

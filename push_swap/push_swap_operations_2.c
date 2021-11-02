/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations_2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharman <kcharman@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:24:33 by kcharman          #+#    #+#             */
/*   Updated: 2021/10/15 20:53:44 by kcharman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **a, int i)
{
	t_stack	*head;
	t_stack	*tail;
	t_stack	*replace;

	if (!(*a) || !(*a)->next)
		return ;
	replace = *a;
	head = (*a)->next;
	tail = *a;
	while (tail->next != NULL)
		tail = tail->next;
	replace->next = NULL;
	tail->next = replace;
	*a = head;
	if (i == 1)
		write(1, "ra\n", 3);
}

void	rb(t_stack **b, int i)
{
	t_stack	*head;
	t_stack	*tail;
	t_stack	*replace;

	if (!(*b) || !(*b)->next)
		return ;
	replace = *b;
	head = (*b)->next;
	tail = *b;
	while (tail->next != NULL)
		tail = tail->next;
	replace->next = NULL;
	tail->next = replace;
	*b = head;
	if (i == 1)
		write(1, "rb\n", 3);
}

void	rr(t_inf *inf)
{
	ra(&inf->a, 0);
	rb(&inf->b, 0);
	write(1, "rr\n", 3);
}

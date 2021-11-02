/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharman <kcharman@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:12:05 by kcharman          #+#    #+#             */
/*   Updated: 2021/10/16 13:21:53 by kcharman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define INT_MAX 2147483647
# define INT_MIN -2147483648
# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				value;
	int				score;
	int				oper_a;
	int				oper_b;
	struct s_stack	*next;
}					t_stack;

typedef struct s_inf
{
	int				count;
	int				count_a;
	int				count_b;
	int				max;
	int				min;
	int				mid;
	t_stack			*a;
	t_stack			*b;
}					t_inf;
int		find_middle(int *arr, int size);
void	ft_swap(int *a, int *b);
long	ft_atoi(const char *str);
int		arg_validation(char **argv);
int		ft_isdigit(int c);
int		duplicate_validation(char **argv);
int		ft_strcmp(const char *s1, const char *s2);
int		*integer_validation(char **argv, int i);
int		args_is_int(char **argv, long *arr);
int		*array_to_int(long *arr, int i);
t_stack	*create_stack(int *arr, int count, t_inf *inf);
void	fill_inf(t_inf *inf, t_stack *a, int count, int *arr);
void	fill_elem(t_stack *elem, int value);
int		is_not_sorted(t_stack *a);
void	arg_error(void);
void	sa(t_stack *a, int i);
void	sb(t_stack *b, int i);
void	ss(t_inf *inf);
void	pa(t_inf *inf);
void	pb(t_inf *inf);
void	ra(t_stack **a, int i);
void	rb(t_stack **b, int i);
void	rr(t_inf *inf);
void	rra(t_stack **a, int i);
void	rrb(t_stack **b, int i);
void	rrr(t_inf *inf);
int		find_max(int *arr, int count);
int		find_min(int *arr, int count);
int		find_max_list(t_stack *stack);
void	start_sort(t_inf *inf);
void	sort_3_elem(t_inf *inf);
void	sort_5_elem(t_inf *inf);
void	sort_elems(t_inf *inf);
t_stack	*find_min_score(t_stack *b);
void	find_score(t_inf *inf);
void	find_score_part2(t_stack *temp);
void	find_operations_b(t_inf *inf);
void	find_operations_a(t_inf *inf);
void	find_operations_a_part2(t_stack *t_a, t_stack *t_b, int i);
void	do_rotate(t_inf *inf, t_stack *min);
void	do_rotate_part2(t_inf *inf, t_stack *min);
void	last_rotate(t_inf *inf);
void	last_rotate_part2(t_inf *inf, int rotates);
void	ft_free(t_inf *inf, int *arr);
void	free_stack(t_stack *stack);
void	ft_free_and_exit(t_inf *inf, t_stack *stack, int *arr);
#endif
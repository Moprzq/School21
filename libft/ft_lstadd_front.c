#include "libft.h"

void	ft_lstadd_front(t_list **begin_list, t_list *new)
{
	t_list	*begin;

	begin = new;
	begin->next = *begin_list;
	*begin_list = begin;
}

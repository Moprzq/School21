#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*current;
	t_list	*head;

	if (!lst)
		return (NULL);
	head = ft_lstnew(f(lst->content));
	if (!head)
		return (NULL);
	current = head;
	while (lst->next)
	{
		current->next = ft_lstnew(f(lst->next->content));
		if (!current->next)
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		current = current->next;
		lst = lst->next;
	}
	return (head);
}

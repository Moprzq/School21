#include <stdlib.h>
#include "libft.h"

void	ft_lstclear(t_list **lst, void(*del)(void *))
{
	t_list	*next;
	t_list	*head;

	head = *lst;
	next = NULL;
	while (head)
	{
		next = head->next;
		if (head->content != NULL)
			del(head->content);
		free(head);
		head = next;
	}
	*lst = NULL;
}

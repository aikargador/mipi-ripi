#include "ft_env.h"

/* Adds the node ’new’ at the end of the list. */
void	ft_lstadd_back(t_lst **lst, t_lst *new)
{
	if (!new || !lst)
		return ;
	if (*lst)
		ft_lstlast(*lst)->next = new;
	else
		*lst = new;
}

/* Adds the node ’new’ at the beginning of the list. */
void	ft_lstadd_front(t_lst **lst, t_lst *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

/* Deletes and frees the given node and every
successor of that node, using the function ’del’
and free(3).
Finally, the pointer to the list must be set to
NULL. */
void	ft_lstclear(t_lst **lst, void (*del)(void *))
{
	t_lst	*dingus;
	t_lst	*chungus;

	dingus = *lst;
	chungus = *lst;
	if (!lst || !del)
		return ;
	while (chungus)
	{
		chungus = dingus->next;
		del(dingus->content);
		free(dingus);
		dingus = chungus;
	}
	*lst = 0;
}

/* Takes as a parameter a node and frees the memory of
the node’s content using the function ’del’ given
as a parameter and free the node. The memory of
’next’ must not be freed. */
void	ft_lstdelone(t_lst *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

/* Iterates the list ’lst’ and applies the function
’f’ on the content of each node. */
void	ft_lstiter(t_lst *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

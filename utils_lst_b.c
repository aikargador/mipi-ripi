#include "ft_env.h"

/* Counts the number of nodes in a list. */
int	ft_lstsize(t_lst *lst)
{
	t_lst	*tmp;
	int		i;

	tmp = lst;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

/* Allocates (with malloc(3)) and returns a new node.
The member variable ’content’ is initialized with
the value of the parameter ’content’. The variable
’next’ is initialized to NULL. */
t_lst	*ft_lstnew(void *content)
{
	t_lst	*tmp;

	tmp = (t_lst *)malloc(sizeof(t_lst));
	if (!tmp)
		return (NULL);
	tmp->content = content;
	tmp->next = NULL;
	return (tmp);
}

/* Returns the last node of the list. */
t_lst	*ft_lstlast(t_lst *lst)
{
	if (lst)
		while (lst->next)
			lst = lst->next;
	return (lst);
}

/* Iterates the list ’lst’ and applies the function
’f’ on the content of each node. Creates a new
list resulting of the successive applications of
the function ’f’. The ’del’ function is used to
delete the content of a node if needed. */
t_lst	*ft_lstmap(t_lst *lst, void *(*f)(void *), void (*del)(void *))
{
	t_lst	*fungus;
	t_lst	*mungus;

	fungus = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		mungus = ft_lstnew(f(lst->content));
		if (!mungus)
		{
			ft_lstclear(&fungus, del);
			return (0);
		}
		ft_lstadd_back(&fungus, mungus);
		lst = lst->next;
	}
	return (fungus);
}

t_lst	*ft_lstcap(char **e, void *(*f)(void *), void (*del)(void *))
{
	t_lst	*fungus;
	t_lst	*mungus;

	int i = -1;
	fungus = 0;
	if (!e)
		return (0);
	while (e[++i])
	{
		mungus = ft_lstnew(f(e[i]));
		if (!mungus)
		{
			ft_lstclear(&fungus, del);
			return (0);
		}
		ft_lstadd_back(&fungus, mungus);
	}
	return (fungus);
}
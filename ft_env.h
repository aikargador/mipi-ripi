#ifndef FT_ENV_H
# define FT_ENV_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_lst {

	char			*content;
	struct s_lst	*next;

} t_lst;

/* ft_env */
void	ft_free_str(char *str);
void	ft_store_env(char **e, t_lst **env_lst);
void	ft_environment(char *e[], t_lst **env_lst);

/* utils1 */
size_t	ft_strlen(const char *s);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);

/* linked lst utils! */
/* utils_lst_a */
void	ft_lstadd_back(t_lst **lst, t_lst *new);
void	ft_lstadd_front(t_lst **lst, t_lst *new);
void	ft_lstclear(t_lst **lst, void (*del)(void *));
void	ft_lstdelone(t_lst *lst, void (*del)(void *));
void	ft_lstiter(t_lst *lst, void (*f)(void *));

/* utils_lst_b */
int		ft_lstsize(t_lst *lst);
t_lst	*ft_lstnew(void *content);
t_lst	*ft_lstlast(t_lst *lst);
t_lst	*ft_lstmap(t_lst *lst, void *(*f)(void *), void (*del)(void *));
t_lst	*ft_lstcap(char **e, void *(*f)(void *), void (*del)(void *));

#endif
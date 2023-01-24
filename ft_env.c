#include "ft_env.h"

void	ft_free_str(char *str)
{
	if (str)
		free (str);
}

void	ft_store_env(char **e, t_lst **env_lst)
{
	t_lst	*tmp;
	t_lst	*tmp2;
	int	l;
	int	i;

	l = 0;
	while (e[l])
		l++;
	i = 0;
	// tmp2 = *env_lst;
	// tmp2 = ft_lstnew(ft_strdup(e[i]));
	// write(1, "hello\n", 6);
	// printf("%s\n", tmp2->content);
	// while (++i < l)
	// {
	// 	tmp = ft_lstnew(ft_strdup(e[i]));
	// 	if (!tmp)
	// 		ft_lstclear(env_lst, (void *)ft_free_str);
	// 	ft_lstadd_back(&tmp2, tmp);
	// 	tmp2 = tmp2->next;
	// 	// write(1, "hello\n", 6);
	// }
	*env_lst = ft_lstcap(e, (void *)ft_strdup, (void *)ft_free_str);
}

/* fake int main */
void	ft_environment(char **e, t_lst **env_lst)
{
	int i = -1;
	while (e[++i]) {
		// printf("%s\n", e[i]);
	}
	ft_store_env(e, env_lst);
	// for (int k = 0; k < i; k++)
	t_lst *pp;
	pp = *env_lst;
	while (pp)
	{
		printf("%s\n", pp->content);
		pp = pp->next;
	}
}


int main(int argc, char *argv[], char *envp[])
{
	t_lst	**env_lst;

	env_lst = malloc(sizeof(t_lst *));
	ft_environment(envp, env_lst);
}














// #include <stdlib.h>
// #include <stdio.h>

// int main(void)
// {
//    const char *pathvar = getenv("PATH");
//    printf("PATH = %s\n", pathvar ? pathvar : "<NULL>");
// }
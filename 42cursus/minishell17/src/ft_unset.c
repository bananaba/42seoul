#include "minishell.h"

int	ft_unset(t_mp *mp, char *target)
{
	t_list	*temp;
	t_list	*temp2;
	int		len;

	temp = mp->envp;
	len = ft_strlen(target);
	if (ft_strncmp(temp->content, target, len) == 0)
	{
		free(temp->content);
		temp->content = NULL;
		mp->envp = mp->envp->next;
		free(temp);
		return (errno);
	}
	while (temp->next != NULL
		&& ft_strncmp(temp->next->content, target, len))
		temp = temp->next;
	if (temp->next == NULL)
		return (errno);
	free(temp->next->content);
	temp2 = temp->next;
	temp->next = temp2->next;
	free(temp2);
	temp2 = NULL;
	return (errno);
}
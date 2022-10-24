
#include "minishell.h"
static void	split_text(t_list *lst);



int	divide_text_in_token(t_list *token_start)
{
	split_text(token_start);
	return (0);
}



static void	split_text(t_list *lst)
{
	t_list	*temp;
	char	**str;
	int		i;

	while (lst)
	{
		if (((t_token *)lst->content)->type == 't'
			&& ft_strchr(((t_token *)lst->content)->text, ' '))
		{
			i = -1;
			str = ft_split(((t_token *)lst->content)->text, ' ');
			while (str[++i])
			{
				temp = (t_list *)malloc(sizeof(t_list));
				temp->content = (void *) new_token('t', ft_strdup(str[i]));
				temp->next = lst->next;
				lst->next = temp;
				lst = temp;
				free(str[i]);
			}
		}
		lst = lst->next;
	}
	free(str);
}
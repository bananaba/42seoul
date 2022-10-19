#include "../includes/minishell.h"

typedef struct s_list
{
	char			*str;
	struct s_list	*next;
}	t_list;

t_list	*new_list(void)
{
	t_list	*temp;

	temp = (t_list *)malloc(sizeof(t_list));
	ft_bzero(temp, sizeof(t_list));
	return (temp);
}

t_list	*array_to_list(char *arr[])
{
	int		i;
	t_list	*temp;

	i = 0;
	while (arr[i])
	{
		
	}
}

char	**list_to_array(t_list *lst)
{}
